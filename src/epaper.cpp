// ============================================================================
// epaper.cpp – Waveshare 2.13" e-Paper (B) Three-Color Display Driver
// Shows: Material, Manufacturer, Colour, Weight
// Isolated SPI handling + non-blocking debounced updates
// ============================================================================
#include "epaper.h"
#include "board_config.h"
#include "logo_bitmap.h"   // Auto-generated logo bitmap

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <GxEPD2_3C.h>
#include <SPI.h>
#include <TFT_eSPI.h>

// Waveshare 2.13" (B) V4 Three-color: 212x104, SSD1680
static GxEPD2_3C<GxEPD2_213_Z98c, GxEPD2_213_Z98c::HEIGHT>
    epaper(GxEPD2_213_Z98c(EPAPER_CS_PIN, EPAPER_DC_PIN, EPAPER_RST_PIN,
                           EPAPER_BUSY_PIN));

static bool epaperReady = false;

// ── SPI Bus Isolation Helpers for E-Paper ──
// Ensure other SPI peripherals (TFT, Touch, RFID) are deselected
static void epaper_spi_lock() {
  digitalWrite(DISPLAY_PIN_CS, HIGH);
  digitalWrite(TOUCH_PIN_CS, HIGH);
  digitalWrite(RFID_SDA_PIN, HIGH);
  #ifdef SET_BUS_READ_MODE
  SET_BUS_READ_MODE;
  #endif
  delayMicroseconds(5);
}

static void epaper_spi_unlock() {
  digitalWrite(EPAPER_CS_PIN, HIGH);
  #ifdef SET_BUS_READ_MODE
  SET_BUS_READ_MODE;
  #endif
  delayMicroseconds(5);
}

// ── Deferred / Debounced Update State ──
static bool updatePending = false;
static unsigned long updateRequestedAt = 0;
static const unsigned long EPAPER_DEBOUNCE_MS = 2500; // Wait 2.5s of idle before 20s e-paper refresh

static char p_material[32] = "PLA";
static char p_manufacturer[32] = "Generic";
static char p_colour[32] = "White";
static float p_weight = 1000.0f;
static int p_maxWeight = 1000;

void epaper_init() {
  Serial.println("E-Paper initialization starting...");

  epaper_spi_lock();

  // Initialize hardware SPI object
  SPI.begin(DISPLAY_PIN_SCLK, DISPLAY_PIN_MISO, DISPLAY_PIN_MOSI);

  // Initialize the e-Paper driver
  epaper.init(115200, true, 200, false);
  epaper.setRotation(1); // Landscape mode
  epaper.setTextWrap(false);

  // Splash screen (clean, no concurrent TFT access)
  Serial.println("E-Paper: Showing logo...");
  epaper.setFullWindow();
  epaper.firstPage();
  do {
    epaper.fillScreen(GxEPD_WHITE);
    epaper.drawBitmap(0, 0, logo_bw, LOGO_WIDTH, LOGO_HEIGHT, GxEPD_BLACK);
    epaper.drawBitmap(0, 0, logo_red, LOGO_WIDTH, LOGO_HEIGHT, GxEPD_RED);
  } while (epaper.nextPage());

  epaperReady = true;
  epaper_spi_unlock();
  Serial.println("E-Paper initialized (2.13\" three-color)");
}

void epaper_request_update(const char *material, const char *manufacturer,
                          const char *colour, float weight, int maxWeight) {
  if (!epaperReady)
    return;

  // Cache latest values
  strncpy(p_material, material ? material : "", sizeof(p_material) - 1);
  p_material[sizeof(p_material) - 1] = '\0';
  strncpy(p_manufacturer, manufacturer ? manufacturer : "", sizeof(p_manufacturer) - 1);
  p_manufacturer[sizeof(p_manufacturer) - 1] = '\0';
  strncpy(p_colour, colour ? colour : "", sizeof(p_colour) - 1);
  p_colour[sizeof(p_colour) - 1] = '\0';
  p_weight = weight;
  p_maxWeight = maxWeight;

  updatePending = true;
  updateRequestedAt = millis();
  Serial.println("E-Paper update queued (debounced)");
}

void epaper_update_spool(const char *material, const char *manufacturer,
                         const char *colour, float weight, int maxWeight) {
  if (!epaperReady)
    return;

  Serial.printf("E-Paper updating: %s / %s / %s / %.0fg / %dg\n", material,
                manufacturer, colour, weight, maxWeight);

  epaper_spi_lock();

  epaper.setFullWindow();
  epaper.firstPage();
  do {
    epaper.fillScreen(GxEPD_WHITE);

    // --- Title bar ---
    epaper.setTextColor(GxEPD_RED);
    epaper.setFont(&FreeSansBold9pt7b);
    epaper.setCursor(4, 16);
    epaper.print("Spool Info");

    // --- Divider line ---
    epaper.drawLine(0, 22, 212, 22, GxEPD_BLACK);

    // --- Spool details ---
    epaper.setTextColor(GxEPD_BLACK);
    epaper.setFont(&FreeSans9pt7b);

    epaper.setCursor(4, 40);
    epaper.print("Mat: ");
    epaper.setFont(&FreeSansBold9pt7b);
    epaper.print(material);

    epaper.setFont(&FreeSans9pt7b);
    epaper.setCursor(4, 58);
    epaper.print("Mfr: ");
    epaper.setFont(&FreeSansBold9pt7b);
    epaper.print(manufacturer);

    epaper.setFont(&FreeSans9pt7b);
    epaper.setCursor(4, 76);
    epaper.print("Col: ");
    epaper.setFont(&FreeSansBold9pt7b);
    epaper.print(colour);

    epaper.setTextColor(GxEPD_RED);
    epaper.setFont(&FreeSansBold9pt7b);
    epaper.setCursor(4, 97);
    char wBuf[32];
    snprintf(wBuf, sizeof(wBuf), "%.0fg / %dg", weight, maxWeight);
    epaper.print(wBuf);
  } while (epaper.nextPage());

  epaper_spi_unlock();
  updatePending = false;
  Serial.println("E-Paper update complete");
}

void epaper_tick() {
  if (updatePending && (millis() - updateRequestedAt >= EPAPER_DEBOUNCE_MS)) {
    updatePending = false;
    epaper_update_spool(p_material, p_manufacturer, p_colour, p_weight, p_maxWeight);
  }
}

bool epaper_is_busy() {
  return updatePending;
}

void epaper_clear() {
  if (!epaperReady)
    return;
  epaper_spi_lock();
  epaper.setFullWindow();
  epaper.firstPage();
  do {
    epaper.fillScreen(GxEPD_WHITE);
  } while (epaper.nextPage());
  epaper_spi_unlock();
  Serial.println("E-Paper cleared");
}
