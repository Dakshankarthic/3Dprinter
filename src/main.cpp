#include <Arduino.h>
#include <DHT.h>
#include <HX711.h>
#include <MFRC522.h>
#include <Preferences.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <WebServer.h>
#include <WiFi.h>
#include <Wire.h>
#include <lvgl.h>

#include "board_config.h"

#include "epaper.h"
#include <TFT_eSPI.h>

#include "ui/button_functions.h"
#include "ui/ui.h"

// Hardware pin definitions
#define DHT_TYPE DHT11

// Wi-Fi
// const char* ssid = "DK 3397";
// const char* password = "58-x268C";
Preferences preferences;

// Objects
HX711 scale;
MFRC522 rfid(RFID_SDA_PIN, RFID_RST_PIN); // Create MFRC522 instance
DHT dht(DHT_PIN, DHT_TYPE);
TFT_eSPI tft = TFT_eSPI(); // Handles Display AND Touch automatically


// State variables
bool uiInitialized = false;
bool wifiConnected = false;
float filamentWeight = 0.0;
float temperature = 0.0;
float humidity = 0.0;
bool isDryingActive = false;
bool isAutoMode = false;
char selectedSSID[33] = "";
char selectedPassword[64] = "";
String wifiStatusMsg = "Not connected";
float scaleCalibrationFactor = 1.0;
bool isScaleReady = false;
bool isDhtReady = false;
bool isRfidReady = false;
float filteredWeight = 0.0; // Global for reset on Tare

// UI variables
int dryingTimeHours = 5;
int dryingTimeMinutes = 45;
int dryingTemperature = 65;
int selectedMaterial = 1;
int selectedManufacturer = 1;
int selectedColor = 1;
int calibrationWeight = 1000;
int currentCalibrationSelection = 1000;

WebServer server(80);

static String getStatusJson() {
  String json = "{";
  json += "\"weight\":" + String(filamentWeight, 2) + ",";
  json += "\"temperature\":" + String(temperature, 1) + ",";
  json += "\"humidity\":" + String(humidity, 1) + ",";
  json += "\"drying\":" + String(isDryingActive ? "true" : "false") + ",";
  json += "\"targetTemp\":" + String(dryingTemperature) + ",";
  json += "\"timeH\":" + String(dryingTimeHours) + ",";
  json += "\"timeM\":" + String(dryingTimeMinutes);
  json += "}";
  return json;
}

static String getIndexHtml() {
  String ip = WiFi.isConnected() ? WiFi.localIP().toString() : String("-");
  String html =
      "<!doctype html><html><head><meta charset='utf-8'>"
      "<meta name='viewport' content='width=device-width,initial-scale=1'>"
      "<title>ESP32 Dryer</title></head><body>"
      "<h2>ESP32 Dryer</h2><div>IP: " +
      ip +
      "</div>"
      "</body></html>";
  return html;
}

static void setup_web_routes() {
  server.on("/", HTTP_GET,
            []() { server.send(200, "text/html", getIndexHtml()); });
  server.on("/api/status", HTTP_GET,
            []() { server.send(200, "application/json", getStatusJson()); });
  server.on("/api/control", HTTP_GET, []() {
    String mode = server.hasArg("drying") ? server.arg("drying") : "";
    if (mode == "on") {
      start_drying_process();
    } else if (mode == "off") {
      stop_drying_process();
    }
    server.send(200, "application/json", getStatusJson());
  });
  server.begin();
  Serial.println("Web server started");
}

// LVGL Flush Callback
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area,
                   lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();
  lv_disp_flush_ready(disp);
}

// LVGL Touch Read Callback (Uses built-in LovyanGFX touch)
void my_touch_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);

  if (touched) {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchX;
    data->point.y = touchY;

    static uint32_t lastDebug = 0;
    if (millis() - lastDebug > 500) {
      Serial.printf("Touch detected -> X=%d, Y=%d\n", touchX, touchY);
      lastDebug = millis();
    }
  } else {
    data->state = LV_INDEV_STATE_REL;
  }
}




void setup_wifi() {
  WiFi.mode(WIFI_STA);
  preferences.begin("wifi-config", true);
  String saved_ssid = preferences.getString("ssid", "");
  String saved_password = preferences.getString("password", "");
  preferences.end();

  if (saved_ssid.length() > 0) {
    strncpy(selectedSSID, saved_ssid.c_str(), sizeof(selectedSSID) - 1);
    strncpy(selectedPassword, saved_password.c_str(),
            sizeof(selectedPassword) - 1);
    wifiStatusMsg = "Connecting...";
    WiFi.begin(selectedSSID, selectedPassword);
  }
}


void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Booting...");

  // 1. PROACTIVE PIN INITIALIZATION: Deselect all SPI devices immediately
  // This prevents bus contention before libraries are fully initialized.
  pinMode(DISPLAY_PIN_CS, OUTPUT);
  digitalWrite(DISPLAY_PIN_CS, HIGH);
  pinMode(TOUCH_PIN_CS, OUTPUT);
  digitalWrite(TOUCH_PIN_CS, HIGH);
  pinMode(RFID_SDA_PIN, OUTPUT);
  digitalWrite(RFID_SDA_PIN, HIGH);
  pinMode(EPAPER_CS_PIN, OUTPUT);
  digitalWrite(EPAPER_CS_PIN, HIGH);

  // 2. Initialize Hardware SPI Object with project-specific pins
  // Used by GxEPD2 and MFRC522 (and now safely shared with TFT_eSPI)
  SPI.begin(DISPLAY_PIN_SCLK, DISPLAY_PIN_MISO, DISPLAY_PIN_MOSI);

  // Pins
  pinMode(HEATER_MOSFET_PIN, OUTPUT);
  digitalWrite(HEATER_MOSFET_PIN, LOW);

  // Fan PWM Setup
  ledcSetup(FAN_PWM_CHANNEL, FAN_PWM_FREQ, FAN_PWM_RES);
  ledcAttachPin(FAN_MOSFET_PIN, FAN_PWM_CHANNEL);
  ledcWrite(FAN_PWM_CHANNEL, 0); // Start off

  // Initialize Display & Touch via LovyanGFX

  // 2. Initialize Main Display & Touch
  Serial.println("Initializing display...");
  pinMode(11, OUTPUT); // TFT_BL
  digitalWrite(11, HIGH);
  delay(100); // Give serial time to flush
  
  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  
  // Basic touch calibration data (can be refined later)
  uint16_t calData[5] = {300, 3400, 200, 3600, 1};
  tft.setTouch(calData);
  
  bool displayInitResult = true;

  if (displayInitResult) {
    Serial.println("Display initialized successfully");

    // Init Sensors
    pinMode(HX711_DOUT_PIN, INPUT_PULLUP);
    pinMode(HX711_SCK_PIN, OUTPUT);
    scale.begin(HX711_DOUT_PIN, HX711_SCK_PIN);

    preferences.begin("scale-init", true);
    scaleCalibrationFactor =
        preferences.getFloat("factor", 226.0); // Default factor
    preferences.end();
    scale.set_scale(scaleCalibrationFactor);

    scale.set_gain(128); // Force high gain
    if (scale.wait_ready_timeout(500)) {
      delay(500);     // Let it settle
      scale.tare(40); // Use 40 samples for a stable zero
      delay(200);     // Let tare settle

      // Seed the EMA filter with the first real reading
      // This prevents the "0 → real value" convergence fluctuation on startup
      if (scale.is_ready()) {
        float firstRead = scale.get_units(5); // Average 5 samples
        filteredWeight = firstRead;           // Seed filter at real value
        filamentWeight = (abs(firstRead) < 5.0) ? 0.0 : firstRead;
      }

      isScaleReady = true;
      Serial.println("HX711 tared and ready (Gain 128)");

    } else {

      isScaleReady = false;
      Serial.println("HX711 not found!");
    }

    dht.begin();
    float t_check = dht.readTemperature();
    isDhtReady = !isnan(t_check);

    // RFID: Init on the shared SPI2 bus (same as display & touch)
    // LovyanGFX already initialized SPI2 with pins 14/12/13
    // MFRC522 uses the global SPI object which is also SPI2
    pinMode(RFID_SDA_PIN, OUTPUT);
    digitalWrite(RFID_SDA_PIN, HIGH); // Deselect RFID before init
    rfid.PCD_Init();
    delay(100);                               // Let RFID module stabilize
    rfid.PCD_SetAntennaGain(rfid.RxGain_max); // Max gain (48dB) for smart cards
    byte v = rfid.PCD_ReadRegister(MFRC522::VersionReg);
    isRfidReady = (v != 0x00 && v != 0xFF);
    Serial.printf("RFID Init: version=0x%02X, ready=%d, gain=0x%02X\n", v,
                  isRfidReady, rfid.PCD_GetAntennaGain());

    // Init LVGL
    lv_init();

    // Print memory info for debugging
    Serial.printf("Free heap: %d bytes\n", ESP.getFreeHeap());
    Serial.printf("PSRAM size: %d bytes, Free PSRAM: %d bytes\n",
                  ESP.getPsramSize(), ESP.getFreePsram());

    // Allocate LVGL buffers - prefer PSRAM, fall back to internal RAM
    const uint32_t buf_pixel_count = 480 * 80;
    lv_color_t *buf1 = (lv_color_t *)heap_caps_malloc(
        buf_pixel_count * sizeof(lv_color_t), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    lv_color_t *buf2 = (lv_color_t *)heap_caps_malloc(
        buf_pixel_count * sizeof(lv_color_t), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);

    if (!buf1 || !buf2) {
      // PSRAM not available - fall back to smaller internal RAM buffer
      Serial.println("PSRAM alloc failed - using internal RAM");
      if (buf1) { free(buf1); buf1 = nullptr; }
      if (buf2) { free(buf2); buf2 = nullptr; }
      uint32_t small_buf = 480 * 40;
      buf1 = (lv_color_t *)malloc(small_buf * sizeof(lv_color_t));
      buf2 = (lv_color_t *)malloc(small_buf * sizeof(lv_color_t));
    }

    static lv_disp_draw_buf_t draw_buf;
    if (!buf1 || !buf2) {
      Serial.println("ERROR: Buffer allocation completely failed!");
    } else {
      bool inPsram = esp_ptr_external_ram(buf1);
      Serial.printf("LVGL buffers in %s RAM (%d bytes each)\n",
                    inPsram ? "PSRAM" : "Internal",
                    (int)(buf_pixel_count * sizeof(lv_color_t)));
      lv_disp_draw_buf_init(&draw_buf, buf1, buf2,
                            inPsram ? buf_pixel_count : 480 * 40);
    }

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 320;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touch_read; // Uses tft.getTouch()
    lv_indev_drv_register(&indev_drv);

    tft.fillScreen(TFT_BLACK);

    // Load saved settings
    // preferences.begin("settings", true);
    // calibrationWeight = preferences.getInt("cal_weight", 1000);
    // currentCalibrationSelection = calibrationWeight;
    // preferences.end();

    // Init UI and Network
    ui_init();
    setup_color_buttons();
    load_filament_data(); // Restore last spool settings from NVS
    uiInitialized = true;
    setup_wifi();
    setup_web_routes(); // Initialize routes; server will be reachable once WiFi
                        // connects
    Serial.println("System Ready");

    // Initialize e-Paper display (after everything else is stable)
    epaper_init();
    trigger_epaper_update();

    // --- TFT BUS RESYNC after E-Paper SPI ---
    // Do NOT call tft.init() - it resets touch calibration.
    // Instead just force a display write to re-assert the bus state.
    Serial.println("Resyncing TFT after E-Paper...");
    digitalWrite(EPAPER_CS_PIN, HIGH);
    digitalWrite(DISPLAY_PIN_CS, HIGH);
    digitalWrite(TOUCH_PIN_CS, HIGH);
    delay(100);
    tft.setRotation(1);
    tft.setSwapBytes(true);
    tft.fillScreen(TFT_BLACK);
    delay(50);
    lv_obj_invalidate(lv_scr_act());
    lv_refr_now(NULL);
    Serial.println("TFT resynced.");

  } else {
    Serial.println("Display Init Failed!");
    // Blink LED to indicate failure if Serial is not visible
    pinMode(LED_PIN, OUTPUT);
    while (true) {
      digitalWrite(LED_PIN, HIGH);
      delay(200);
      digitalWrite(LED_PIN, LOW);
      delay(200);
    }
  }
}

void loop() {
  lv_timer_handler();
  check_wifi_scan_results();
  update_wifi_status_logic();

  server.handleClient();

  static unsigned long lastSensorRead = 0;
  if (millis() - lastSensorRead > 1000) { // Update every 1s
    lastSensorRead = millis();

    if (scale.is_ready()) {
      // Let the HX711 library average 10 samples internally (most reliable)
      float raw = scale.get_units(10);

      // EMA: smooth out reading-to-reading noise
      filteredWeight = (filteredWeight * 0.5f) + (raw * 0.5f);

      // Deadzone: clamp small values to 0 to prevent display jitter
      if (abs(filteredWeight) < 10.0f) {
        filamentWeight = 0.0f;
      } else {
        // Round to nearest 5g for a clean display
        filamentWeight = round(filteredWeight / 5.0f) * 5.0f;
      }

      isScaleReady = true;
      Serial.printf("Scale: raw=%.1f filtered=%.1f display=%.0f\n",
                    raw, filteredWeight, filamentWeight);


    } else {
      // If sensor isn't ready, don't clear the weight immediately (anti-blink)
      if (millis() - lastSensorRead > 10000)
        isScaleReady = false;
    }

    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (!isnan(t)) {
      temperature = t;
      humidity = h;
      isDhtReady = true;
    } else {
      isDhtReady = false;
    }

    // Simple RFID presence check
    byte v_live = rfid.PCD_ReadRegister(MFRC522::VersionReg);
    isRfidReady = (v_live != 0x00 && v_live != 0xFF);
    static unsigned long lastRfidInit = 0;
    if (!isRfidReady && (millis() - lastRfidInit > 10000)) {
      lastRfidInit = millis();
      rfid.PCD_Init();
    }

    // RFID spool management – check for card tap (inside sensor block to
    // avoid SPI conflicts with display)
    rfid_check_and_handle();

    if (uiInitialized) {
      ui_tick();
      update_ui_sensor_data();
    }
  }

  // Control drying process (heater/fan)
  control_drying_process();

  // Heartbeat blink
  static uint32_t lastBlink = 0;
  if (millis() - lastBlink > 1000) {
    lastBlink = millis();
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }

  delay(5);
}

void tare_scale() {
  scale.tare(40);       // High sample tare
  filteredWeight = 0.0; // Force filter reset
  filamentWeight = 0.0;
  Serial.println("Scale zeroed and filter reset");
}

void calibrate_scale(int known_weight_g) {
  if (!isScaleReady || known_weight_g <= 0)
    return;

  // Let the weight settle
  delay(800);

  // Step 1: Get raw average (contains offset)
  long raw = scale.read_average(30);
  long offset = scale.get_offset();
  float raw_load = (float)(raw - offset);

  // Step 2: Protection against empty scale calibration
  if (abs(raw_load) < 500) {
    Serial.println("CALIBRATION FAILED: Load is too small. Did you place the "
                   "physical weight?");
    return;
  }

  // Step 3: Math
  scaleCalibrationFactor = raw_load / (float)known_weight_g;
  scale.set_scale(scaleCalibrationFactor);

  // Step 4: Save
  preferences.begin("scale-init", false);
  preferences.putFloat("factor", scaleCalibrationFactor);
  preferences.end();

  Serial.printf("CALIBRATION SUCCESS: Raw=%ld, Offset=%ld, Load=%0.1f, "
                "Weight=%dg -> New Factor: %.4f\n",
                raw, offset, raw_load, known_weight_g, scaleCalibrationFactor);
}