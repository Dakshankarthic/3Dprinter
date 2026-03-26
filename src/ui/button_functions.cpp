// ============================================================================
// button_functions.cpp  –  Filament-Spool Data Capture & UI Update Logic
// ============================================================================
#include "button_functions.h"
#include "../epaper.h"
#include "board_config.h"
#include "screens.h"
#include "ui.h"
#include <Arduino.h>
#include <MFRC522.h>
#include <Preferences.h>
#include <WiFi.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>

// --- Extern variables from main.cpp
extern bool isDryingActive;
extern bool isAutoMode;
extern char selectedSSID[33];
extern char selectedPassword[64];
extern String wifiStatusMsg;
extern Preferences preferences;
extern int calibrationWeight;
extern float filamentWeight;
extern float temperature;
extern float humidity;
extern bool wifiConnected;
extern int selectedMaterial;
extern int selectedManufacturer;
extern int selectedColor;
extern int dryingTimeHours;
extern int dryingTimeMinutes;
extern int dryingTemperature;
extern bool isScaleReady;
extern bool isDhtReady;
extern bool isRfidReady;

// --- Module state
unsigned long dryingStartTime = 0;
int fanSpeed = 255;

// --- Stored selections
static char s_material[32] = "PC Blend";
static char s_hersteller[32] = "Prusament";
static char s_colour[32] = "Galaxy Black";
static int s_maxWeight = 1000;

// --- Mapping tables
static const char *HERSTELLER_BY_OBJ[9] = {"",        "Prusament", "Bambu Lab",
                                           "eSun",    "Polymaker", "Extrudr",
                                           "Nobofil", "Sunlu",     "Andere"};
static const char *MATERIAL_BY_OBJ[13] = {
    "",    "PLA", "PLA-CF", "PLA+", "ABS", "PETG", "PETG-CF",
    "ASA", "PP",  "PC",     "TPU",  "PA",  "PVA"};
static const char *COLOUR_BY_OBJ[13] = {"",
                                        "Galaxy Black",
                                        "Jet Black",
                                        "Snow White",
                                        "Ivory White",
                                        "Traffic Red",
                                        "Ocean Blue",
                                        "Forest Green",
                                        "Sunset Orange",
                                        "Royal Purple",
                                        "Sunny Yellow",
                                        "Steel Gray",
                                        "Silver"};

// --- Spool history tracking
struct SpoolHistory {
  char manufacturer[32];
  char material[32];
  char color[32];
  int maxWeight;
  float actualWeight;
};
static SpoolHistory spool_history[3] = {
    {"Polymaker", "PETG-CF", "Schwarz", 1000, 458},
    {"Nobofil", "PC-Blend", "Silver", 800, 654},
    {"eSun", "PLA", "Weiss", 1000, 60}};
static int history_count = 3;

static void refresh_history_ui() {
  lv_obj_t *mf[] = {objects.spulen_daten_hersteller_material_farbe_1,
                    objects.spulen_daten_hersteller_material_farbe_2,
                    objects.spulen_daten_hersteller_material_farbe_3};
  lv_obj_t *gw[] = {objects.spulen_daten_gewicht_1,
                    objects.spulen_daten_gewicht_2,
                    objects.spulen_daten_gewicht_3};

  for (int i = 0; i < 3; i++) {
    if (i < history_count && mf[i] && gw[i]) {
      char buf[128];
      snprintf(buf, sizeof(buf), "%s %s %s", spool_history[i].manufacturer,
               spool_history[i].material, spool_history[i].color);
      lv_label_set_text(mf[i], buf);
      snprintf(buf, sizeof(buf), "%.0fg / %dg", spool_history[i].actualWeight,
               spool_history[i].maxWeight);
      lv_label_set_text(gw[i], buf);
    }
  }
}

// --- E-Paper helper
void trigger_epaper_update() {
  epaper_update_spool(s_material, s_hersteller, s_colour, filamentWeight,
                      s_maxWeight);
}

// --- UI Synchronization
void crawl_and_sync(lv_obj_t *obj, const char *old_txt, const char *new_txt) {
  if (!obj || !old_txt || !new_txt)
    return;

  // Check if this object is a label and matches the old text
  if (lv_obj_check_type(obj, &lv_label_class)) {
    const char *curr = lv_label_get_text(obj);
    if (curr && strcmp(curr, old_txt) == 0) {
      lv_label_set_text(obj, new_txt);
    }
  }

  // Recurse into children
  uint32_t cnt = lv_obj_get_child_cnt(obj);
  for (uint32_t i = 0; i < cnt; i++) {
    crawl_and_sync(lv_obj_get_child(obj, i), old_txt, new_txt);
  }
}

void sync_ui_labels(const char *old_txt, const char *new_txt) {
  if (!old_txt || !new_txt || strcmp(old_txt, new_txt) == 0)
    return;

  // List of all known screens to crawl
  lv_obj_t *screens[] = {objects.homescreen,
                         objects.neue_spule_material_screen,
                         objects.neue_spule_hersteller_screen,
                         objects.neue_spule_farbe_screen,
                         objects.trocknenscreen,
                         objects.einstellungen_screen,
                         objects.netzwerksuche_screen,
                         objects.ssid_screen,
                         objects.passworteingabe_screen,
                         objects.system_screen,
                         objects.spulen_daten_screen,
                         objects.system_farben_preset,
                         objects.system_hersteller_preset};

  for (auto s : screens) {
    if (s)
      crawl_and_sync(s, old_txt, new_txt);
  }
}

static void add_to_history() {
  // Push back
  for (int i = 2; i > 0; i--) {
    spool_history[i] = spool_history[i - 1];
  }
  strncpy(spool_history[0].manufacturer, s_hersteller, 31);
  strncpy(spool_history[0].material, s_material, 31);
  strncpy(spool_history[0].color, s_colour, 31);
  spool_history[0].maxWeight = s_maxWeight;
  spool_history[0].actualWeight = filamentWeight;
  if (history_count < 3)
    history_count++;
  refresh_history_ui();
}

static void refresh_weight_label() {
  if (objects.trocknung_temperaturannzeige_3) {
    char buf[16];
    snprintf(buf, sizeof(buf), "%dg", s_maxWeight);
    lv_label_set_text(objects.trocknung_temperaturannzeige_3, buf);
  }
}

static void refresh_home_labels() {
  if (objects.hersteller_material) {
    char buf[80];
    snprintf(buf, sizeof(buf), "%s  %s", s_hersteller, s_material);
    lv_label_set_text(objects.hersteller_material, buf);
  }

  if (objects.farbe)
    lv_label_set_text(objects.farbe, s_colour);

  if (objects.gewicht) {
    char buf[32];
    if (isScaleReady) {
      snprintf(buf, sizeof(buf), "%.0fg / %dg", filamentWeight, s_maxWeight);
    } else {
      snprintf(buf, sizeof(buf), "No Sensor / %dg", s_maxWeight);
    }
    lv_label_set_text(objects.gewicht, buf);
  }

  // Network Status
  if (objects.ip_label) {
    if (WiFi.status() == WL_CONNECTED) {
      char ipBuf[32];
      snprintf(ipBuf, sizeof(ipBuf), "IP: %s",
               WiFi.localIP().toString().c_str());
      lv_label_set_text(objects.ip_label, ipBuf);
    } else {
      lv_label_set_text(objects.ip_label, "Not Connected");
    }
  }

  if (objects.wlan_button_text_1) {
    if (WiFi.status() == WL_CONNECTED) {
      char ssidBuf[64];
      snprintf(ssidBuf, sizeof(ssidBuf), "Wifi: %s", WiFi.SSID().c_str());
      lv_label_set_text(objects.wlan_button_text_1, ssidBuf);
    } else {
      lv_label_set_text(objects.wlan_button_text_1, wifiStatusMsg.c_str());
    }
  }
}

static void refresh_bar(lv_obj_t *bar) {
  if (!bar)
    return;
  int pct = (s_maxWeight > 0)
                ? (int)((filamentWeight / (float)s_maxWeight) * 100.0f)
                : 0;
  if (pct < 0)
    pct = 0;
  if (pct > 100)
    pct = 100;
  lv_bar_set_value(bar, pct, LV_ANIM_OFF);
}

static void refresh_all_bars() {
  refresh_bar(objects.filamentanzeige);
  refresh_bar(objects.filamentanzeige_1);
  refresh_bar(objects.filamentanzeige_2);
  refresh_bar(objects.filamentanzeige_3);
}

static void refresh_drying_ui() {
  char buf[32];
  if (objects.trocknung_temperaturannzeige) {
    snprintf(buf, sizeof(buf), "%dC°", dryingTemperature);
    lv_label_set_text(objects.trocknung_temperaturannzeige, buf);
  }
  if (objects.trocknung_stundenanzeige) {
    snprintf(buf, sizeof(buf), "%dh", dryingTimeHours);
    lv_label_set_text(objects.trocknung_stundenanzeige, buf);
  }
  if (objects.trocknung_minutenanzeige) {
    snprintf(buf, sizeof(buf), "%dmin", dryingTimeMinutes);
    lv_label_set_text(objects.trocknung_minutenanzeige, buf);
  }
  if (objects.trocknungszeit_zeit_3) {
    float decimalTime = dryingTimeHours + (dryingTimeMinutes / 60.0f);
    snprintf(buf, sizeof(buf), "%.2fh", decimalTime);
    lv_label_set_text(objects.trocknungszeit_zeit_3, buf);
  }
  if (objects.start_button_text)
    lv_label_set_text(objects.start_button_text,
                      isDryingActive ? "Stop" : "Start");
}

// --- Callbacks
static void cb_material_btn(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  lv_obj_t *label = lv_obj_get_child(target, 0);
  if (label) {
    const char *text = lv_label_get_text(label);
    if (strcmp(text, "Andere") != 0) {
      strncpy(s_material, text, 31);
    }
  }
  if (objects.neue_spule_hersteller_screen)
    lv_scr_load_anim(objects.neue_spule_hersteller_screen,
                     LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
}

static void cb_hersteller_btn(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  lv_obj_t *label = lv_obj_get_child(target, 0);
  if (label) {
    const char *text = lv_label_get_text(label);
    if (strcmp(text, "Andere") != 0) {
      strncpy(s_hersteller, text, 31);
    }
  }
  if (objects.neue_spule_farbe_screen)
    lv_scr_load_anim(objects.neue_spule_farbe_screen, LV_SCR_LOAD_ANIM_FADE_IN,
                     200, 0, false);
}

static void cb_farbe_btn(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  lv_obj_t *label = lv_obj_get_child(target, 0);
  if (label) {
    const char *text = lv_label_get_text(label);
    if (strcmp(text, "Andere") != 0 && strcmp(text, "Orange") != 0) {
      strncpy(s_colour, text, 31);
      add_to_history(); // Save to history on final selection
      refresh_home_labels();
      save_filament_data(); // Persist to NVS
    } else {
      return; // Handled by specialized keyboard hooks
    }
  }

  if (objects.homescreen)
    lv_scr_load_anim(objects.homescreen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0,
                     false);
}

static void cb_weight_plus(lv_event_t *e) {
  s_maxWeight += 50;
  if (s_maxWeight > 5000)
    s_maxWeight = 5000;
  calibrationWeight = s_maxWeight;
  refresh_weight_label();
  refresh_all_bars();
  trigger_epaper_update();
}
static void cb_weight_minus(lv_event_t *e) {
  s_maxWeight -= 50;
  if (s_maxWeight < 50)
    s_maxWeight = 50;
  calibrationWeight = s_maxWeight;
  refresh_weight_label();
  refresh_all_bars();
  trigger_epaper_update();
}
static void cb_weight_preset_1000(lv_event_t *e) {
  s_maxWeight = 1000;
  calibrationWeight = s_maxWeight;
  refresh_weight_label();
  refresh_all_bars();
  trigger_epaper_update();
}
static void cb_weight_preset_500(lv_event_t *e) {
  s_maxWeight = 500;
  calibrationWeight = s_maxWeight;
  refresh_weight_label();
  refresh_all_bars();
  trigger_epaper_update();
}

static void cb_weight_calibrate(lv_event_t *e) {
  char buf[128];
  snprintf(buf, sizeof(buf), "Calibrating with %dg...\nPlease wait.",
           calibrationWeight);
  lv_obj_t *mbox_wait = lv_msgbox_create(NULL, "Calibration", buf, NULL, true);
  lv_obj_center(mbox_wait);

  // Small delay for UI to show
  lv_refr_now(NULL);

  calibrate_scale(calibrationWeight);

  lv_msgbox_close(mbox_wait);

  // Note: Since calibrate_scale returns void, we assume Success unless the
  // Serial shows failure. In a future update, we could make calibrate_scale
  // return a bool.
  lv_obj_t *mbox = lv_msgbox_create(
      NULL, "Done", "Calibration finished!\nCheck Serial for details.", NULL,
      true);
  lv_obj_center(mbox);
}

static void cb_weight_tare(lv_event_t *e) {
  tare_scale();
  lv_obj_t *mbox = lv_msgbox_create(NULL, "Tare", "Scale zeroed.", NULL, true);
  lv_obj_center(mbox);
}

static void cb_dry_temp_plus(lv_event_t *e) {

  dryingTemperature++;
  if (dryingTemperature > 90)
    dryingTemperature = 90;
  refresh_drying_ui();
}
static void cb_dry_temp_minus(lv_event_t *e) {
  dryingTemperature--;
  if (dryingTemperature < 20)
    dryingTemperature = 20;
  refresh_drying_ui();
}
static void cb_dry_time_plus(lv_event_t *e) {
  dryingTimeMinutes += 15;
  if (dryingTimeMinutes >= 60) {
    dryingTimeMinutes = 0;
    dryingTimeHours++;
  }
  if (dryingTimeHours > 48)
    dryingTimeHours = 48;
  refresh_drying_ui();
}
static void cb_dry_time_minus(lv_event_t *e) {
  dryingTimeMinutes -= 15;
  if (dryingTimeMinutes < 0) {
    if (dryingTimeHours > 0) {
      dryingTimeMinutes = 45;
      dryingTimeHours--;
    } else
      dryingTimeMinutes = 0;
  }
  refresh_drying_ui();
}
static void cb_dry_preset_pla(lv_event_t *e) {
  dryingTemperature = 45;
  dryingTimeHours = 5;
  dryingTimeMinutes = 0;
  refresh_drying_ui();
}
static void cb_dry_preset_petg(lv_event_t *e) {
  dryingTemperature = 65;
  dryingTimeHours = 6;
  dryingTimeMinutes = 0;
  refresh_drying_ui();
}
static void cb_dry_preset_abs(lv_event_t *e) {
  dryingTemperature = 75;
  dryingTimeHours = 6;
  dryingTimeMinutes = 0;
  refresh_drying_ui();
}
static void cb_dry_preset_tpu(lv_event_t *e) {
  dryingTemperature = 55;
  dryingTimeHours = 8;
  dryingTimeMinutes = 0;
  refresh_drying_ui();
}
static void cb_dry_start_stop(lv_event_t *e) {
  if (isDryingActive)
    stop_drying_process();
  else
    start_drying_process();
  refresh_drying_ui();
}
static void cb_dry_auto_switch(lv_event_t *e) {
  isAutoMode = lv_obj_has_state(lv_event_get_target(e), LV_STATE_CHECKED);
}

// --- Wi-Fi List Click
static void cb_wifi_list_btn(lv_event_t *e) {
  lv_obj_t *target = lv_event_get_target(e);
  const char *ssid = lv_list_get_btn_text(objects.obj0, target);
  if (ssid) {
    strncpy(selectedSSID, ssid, 32);
    selectedPassword[0] = '\0';
    if (objects.passworteingabe_screen)
      lv_scr_load_anim(objects.passworteingabe_screen, LV_SCR_LOAD_ANIM_FADE_IN,
                       200, 0, false);
  }
}

// --- Keyboard Logic
static void cb_keyboard_custom(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *k = lv_event_get_target(e);
  lv_obj_t *l = (lv_obj_t *)lv_event_get_user_data(e);
  char *target = (char *)lv_obj_get_user_data(l);

  // Ready (Tick) or Cancel (Close/Exit)
  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    if (code == LV_EVENT_READY) {
      // Determine context based on pointers - most reliable way
      bool isMaterial = (target == s_material);
      bool isManufacturer = (target == s_hersteller);
      bool isColor = (target == s_colour);
      bool isWiFiPass = (target == selectedPassword);
      bool isWiFiSSID =
          (target == selectedSSID ||
           (!isMaterial && !isManufacturer && !isColor && !isWiFiPass));

      if (isWiFiSSID) {
        if (objects.passworteingabe_screen) {
          lv_scr_load_anim(objects.passworteingabe_screen,
                           LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
        }
      } else if (isWiFiPass) {
        wifiStatusMsg = "Connecting...";
        WiFi.begin(selectedSSID, selectedPassword);
        if (objects.homescreen)
          lv_scr_load_anim(objects.homescreen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0,
                           false);
      } else {
        // Custom entry (Color, Manufacturer or Material)
        add_to_history();
        refresh_home_labels();
        save_filament_data(); // Persist to NVS

        // Update the source button label if one was provided
        if (objects.ssid_screen) {
          lv_obj_t *source_btn =
              (lv_obj_t *)lv_obj_get_user_data(objects.ssid_screen);
          if (source_btn) {
            lv_obj_t *btn_label = lv_obj_get_child(source_btn, 0);
            if (btn_label) {
              const char *btn_txt = lv_label_get_text(btn_label);
              if (strcmp(btn_txt, "Andere") != 0 &&
                  strcmp(btn_txt, "Other") != 0) {
                sync_ui_labels(btn_txt, target);
                lv_label_set_text(btn_label, target);
              }
            }
          }
        }

        if (objects.homescreen)
          lv_scr_load_anim(objects.homescreen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0,
                           false);
      }
      // CRITICAL: Stop propagation so the flow engine doesn't move to next
      // screen!
      lv_event_stop_processing(e);
    } else {
      // Cancel
      if (objects.homescreen)
        lv_scr_load_anim(objects.homescreen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0,
                         false);
      lv_event_stop_processing(e);
    }
    return;
  }

  if (code == LV_EVENT_VALUE_CHANGED) {
    uint32_t btn_id = lv_btnmatrix_get_selected_btn(k);
    if (btn_id == LV_BTNMATRIX_BTN_NONE)
      return;
    const char *txt = lv_btnmatrix_get_btn_text(k, btn_id);
    if (!txt)
      return;

    if (strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
      size_t len = strlen(target);
      if (len > 0)
        target[len - 1] = '\0';
    } else if (strcmp(txt, LV_SYMBOL_OK) == 0 || strcmp(txt, "OK") == 0 ||
               strcmp(txt, "Enter") == 0 ||
               strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
      // Trigger READY logic
      lv_event_send(k, LV_EVENT_READY, nullptr);
    } else if (strcmp(txt, "ABC") == 0 || strcmp(txt, "abc") == 0 ||
               strcmp(txt, "1#") == 0 || strcmp(txt, "123") == 0 ||
               strcmp(txt, LV_SYMBOL_KEYBOARD) == 0 ||
               strcmp(txt, LV_SYMBOL_LEFT) == 0 ||
               strcmp(txt, LV_SYMBOL_RIGHT) == 0 ||
               strcmp(txt, LV_SYMBOL_CLOSE) == 0) {
      // Ignore mode/control buttons
    } else {
      size_t limit = (target == selectedSSID)
                         ? 31
                         : 31; // Safety first, all our buffers are 32
      if (strlen(target) < limit) {
        strncat(target, txt, limit - strlen(target));
      }
    }
    lv_label_set_text(l, target);
  }
}

// --- Setup
void setup_color_buttons() {
  auto hook = [](lv_obj_t *o, lv_event_cb_t c, void *ud = nullptr) {
    if (o)
      lv_obj_add_event_cb(o, c, LV_EVENT_CLICKED, ud);
  };

  // Material buttons
  lv_obj_t *m[] = {
      objects.material_1,  objects.material_2,  objects.material_3,
      objects.material_4,  objects.material_5,  objects.material_6,
      objects.material_7,  objects.material_8,  objects.material_9,
      objects.material_10, objects.material_11, objects.material_12};
  for (auto btn : m)
    if (btn)
      lv_obj_add_event_cb(btn, cb_material_btn, LV_EVENT_CLICKED, nullptr);

  // Manufacturer buttons (including system presets)
  lv_obj_t *h[] = {
      objects.hersteller_1,  objects.hersteller_2,  objects.hersteller_3,
      objects.hersteller_4,  objects.hersteller_5,  objects.hersteller_6,
      objects.hersteller_7,  objects.hersteller_8,  objects.hersteller_9,
      objects.hersteller_11, objects.hersteller_13, objects.hersteller_17,
      objects.hersteller_20, objects.hersteller_22, objects.hersteller_24,
      objects.hersteller_26};
  for (auto btn : h)
    if (btn)
      lv_obj_add_event_cb(btn, cb_hersteller_btn, LV_EVENT_CLICKED, nullptr);

  // Color buttons (including system presets)
  lv_obj_t *f[] = {
      objects.farbe_1,  objects.farbe_2,  objects.farbe_3,  objects.farbe_4,
      objects.farbe_5,  objects.farbe_6,  objects.farbe_7,  objects.farbe_8,
      objects.farbe_9,  objects.farbe_10, objects.farbe_11, objects.farbe_12,
      objects.farbe_13, objects.farbe_15, objects.farbe_17, objects.farbe_19,
      objects.farbe_21, objects.farbe_23, objects.farbe_27, objects.farbe_29,
      objects.farbe_31, objects.farbe_33};
  for (auto btn : f) {
    if (btn) {
      lv_obj_set_style_bg_color(btn, lv_color_hex(0xFFFFFF), 0);
      lv_obj_add_event_cb(btn, cb_farbe_btn, LV_EVENT_CLICKED, nullptr);
    }
  }

  hook(objects.obj8, cb_weight_plus);
  hook(objects.obj7, cb_weight_minus);
  hook(objects.kalibrirung_preeset_8, cb_weight_preset_1000);
  hook(objects.kalibrirung_preeset_9, cb_weight_preset_500);

  // Add Tare and Calibrate bindings
  if (objects.gewicht) {
    lv_obj_add_flag(objects.gewicht, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(objects.gewicht, cb_weight_tare, LV_EVENT_LONG_PRESSED,
                        NULL);
  }
  // Removed CLICKED tare to prevent accidents while navigating
  if (objects.hx711) {
    lv_obj_add_flag(objects.hx711, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(objects.hx711, cb_weight_tare, LV_EVENT_LONG_PRESSED,
                        NULL);
  }

  // Use the 1000g calibration preset button for ACTUAL calibration when
  // long-pressed
  if (objects.kalibrirung_preeset_8) {
    lv_obj_add_event_cb(objects.kalibrirung_preeset_8, cb_weight_calibrate,
                        LV_EVENT_LONG_PRESSED, NULL);
  }

  hook(objects.trocknung_preeset_1, cb_dry_preset_pla);
  hook(objects.trocknung_preeset_2, cb_dry_preset_petg);
  hook(objects.trocknung_preeset_3, cb_dry_preset_abs);
  hook(objects.trocknung_preeset_4, cb_dry_preset_tpu);
  hook(objects.obj16, cb_dry_temp_plus);
  hook(objects.obj18, cb_dry_temp_minus);
  hook(objects.obj15, cb_dry_time_plus);
  hook(objects.obj14, cb_dry_time_minus);
  hook(objects.start_button_9, cb_dry_start_stop);
  if (objects.obj17)
    lv_obj_add_event_cb(objects.obj17, cb_dry_auto_switch,
                        LV_EVENT_VALUE_CHANGED, nullptr);

  // Wi-Fi Rescan & Manuel
  if (objects.wlan_button_1) {
    lv_obj_add_event_cb(
        objects.wlan_button_1,
        [](lv_event_t *e) {
          wifiStatusMsg = "Scanning...";
          WiFi.mode(WIFI_STA);
          WiFi.scanNetworks(true);
        },
        LV_EVENT_CLICKED, nullptr);
  }

  hook(objects.erneute_netzwerksuche_button, [](lv_event_t *e) {
    wifiStatusMsg = "Scanning...";
    WiFi.scanNetworks(true);
  });

  // Color custom handlers
  auto go_custom = [](char *buf, const char *title, lv_obj_t *btn = nullptr) {
    if (objects.ssid_screen) {
      if (objects.ssid__berschrift_1)
        lv_label_set_text(objects.ssid__berschrift_1, title);

      // Store the source button so we can update its label later
      lv_obj_set_user_data(objects.ssid_screen, btn);

      // If a button was clicked, use its text as the starting point
      if (btn) {
        lv_obj_t *l = lv_obj_get_child(btn, 0);
        if (l)
          strncpy(buf, lv_label_get_text(l), 31);
      }

      lv_obj_set_user_data(objects.ssid_label, buf);
      lv_label_set_text(objects.ssid_label, buf);
      lv_scr_load_anim(objects.ssid_screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0,
                       false);
    }
  };

  hook(
      objects.manuele_netzwerksuche_button_1,
      [](lv_event_t *e) {
        auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
        selectedSSID[0] = '\0'; // Clear before manual entry
        (*p)(selectedSSID, "SSID:", nullptr);
      },
      (void *)&go_custom);

  // Color selection in System Settings -> Farbauswahl
  lv_obj_t *pref_colors[] = {
      objects.farbe_13, objects.farbe_15, objects.farbe_17, objects.farbe_19,
      objects.farbe_21, objects.farbe_23, objects.farbe_25, objects.farbe_27,
      objects.farbe_29, objects.farbe_31, objects.farbe_33, objects.farbe_35};
  for (auto btn : pref_colors) {
    if (btn) {
      lv_obj_add_event_cb(
          btn,
          [](lv_event_t *e) {
            auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
            (*p)(s_colour, "Farbe:", lv_event_get_target(e));
          },
          LV_EVENT_CLICKED, (void *)&go_custom);
    }
  }

  // Manufacturer selection in System Settings -> Herstellerauswahl
  lv_obj_t *pref_manufacturers[] = {
      objects.hersteller_9,  objects.hersteller_11, objects.hersteller_13,
      objects.hersteller_17, objects.hersteller_20, objects.hersteller_22,
      objects.hersteller_24, objects.hersteller_26, objects.hersteller_27};
  for (auto btn : pref_manufacturers) {
    if (btn) {
      lv_obj_add_event_cb(
          btn,
          [](lv_event_t *e) {
            auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
            (*p)(s_hersteller, "Hersteller:", lv_event_get_target(e));
          },
          LV_EVENT_CLICKED, (void *)&go_custom);
    }
  }

  // 'Andere' buttons on primary screens
  if (objects.material_12)
    lv_obj_add_event_cb(
        objects.material_12,
        [](lv_event_t *e) {
          auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
          (*p)(s_material, "Material:", nullptr);
        },
        LV_EVENT_CLICKED, (void *)&go_custom);

  if (objects.hersteller_8)
    lv_obj_add_event_cb(
        objects.hersteller_8,
        [](lv_event_t *e) {
          auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
          (*p)(s_hersteller, "Hersteller:", nullptr);
        },
        LV_EVENT_CLICKED, (void *)&go_custom);

  if (objects.farbe_12)
    lv_obj_add_event_cb(
        objects.farbe_12,
        [](lv_event_t *e) {
          auto p = (decltype(go_custom) *)lv_event_get_user_data(e);
          (*p)(s_colour, "Farbe:", nullptr);
        },
        LV_EVENT_CLICKED, (void *)&go_custom);

  // Keyboards find and bind
  auto find_kbd = [](lv_obj_t *s) -> lv_obj_t * {
    if (!s)
      return nullptr;
    for (uint32_t i = 0; i < lv_obj_get_child_cnt(s); i++) {
      lv_obj_t *c = lv_obj_get_child(s, i);
      if (lv_obj_check_type(c, &lv_keyboard_class))
        return c;
    }
    return nullptr;
  };
  auto bind_kbd = [](lv_obj_t *k, lv_obj_t *l, char *t) {
    if (!k || !l)
      return;
    lv_keyboard_set_textarea(k, nullptr);
    lv_obj_add_event_cb(k, cb_keyboard_custom, LV_EVENT_ALL, l);
    lv_obj_set_user_data(l, t);
    lv_label_set_text(l, t);
  };

  bind_kbd(find_kbd(objects.ssid_screen), objects.ssid_label, selectedSSID);
  bind_kbd(find_kbd(objects.passworteingabe_screen), objects.password_label,
           selectedPassword);

  refresh_drying_ui();
  refresh_home_labels();
  refresh_history_ui();
  refresh_all_bars();
}

void update_ui_sensor_data() {
  refresh_home_labels();
  refresh_all_bars();

  // Update System Screen status LEDs
  if (objects.system_screen && lv_scr_act() == objects.system_screen) {
    if (objects.rfid) {
      lv_led_set_color(objects.rfid, isRfidReady ? lv_color_hex(0x275722)
                                                 : lv_color_hex(0xFF0000));
      isRfidReady ? lv_led_on(objects.rfid) : lv_led_off(objects.rfid);
    }
    if (objects.hx711) {
      lv_led_set_color(objects.hx711, isScaleReady ? lv_color_hex(0x275722)
                                                   : lv_color_hex(0xFF0000));
      isScaleReady ? lv_led_on(objects.hx711) : lv_led_off(objects.hx711);
    }
    if (objects.heizelement) {
      lv_led_set_color(objects.heizelement, isDryingActive
                                                ? lv_color_hex(0x275722)
                                                : lv_color_hex(0x808080));
      isDryingActive ? lv_led_on(objects.heizelement)
                     : lv_led_off(objects.heizelement);
    }
    // E-Paper is always "ready" if initialized
    if (objects.e_paper) {
      lv_led_set_color(objects.e_paper, lv_color_hex(0x275722));
      lv_led_on(objects.e_paper);
    }
  }
}

void start_drying_process() {
  if (isDryingActive)
    return;
  isDryingActive = true;
  dryingStartTime = millis();
  ledcWrite(FAN_PWM_CHANNEL, fanSpeed);
}
void stop_drying_process() {
  if (!isDryingActive)
    return;
  isDryingActive = false;
  digitalWrite(HEATER_MOSFET_PIN, LOW);
  ledcWrite(FAN_PWM_CHANNEL, 0);
}

void control_drying_process() {
  if (!isDryingActive) {
    digitalWrite(HEATER_MOSFET_PIN, LOW);
    ledcWrite(FAN_PWM_CHANNEL, 0);
    return;
  }
  if (isAutoMode) {
    if (temperature < (float)dryingTemperature - 0.5f)
      digitalWrite(HEATER_MOSFET_PIN, HIGH);
    else if (temperature > (float)dryingTemperature + 0.5f)
      digitalWrite(HEATER_MOSFET_PIN, LOW);
    if (objects.trocknungszeit_zeit)
      lv_label_set_text(objects.trocknungszeit_zeit, "AUTO");
    return;
  }
  unsigned long totalMs =
      (dryingTimeHours * 3600UL + dryingTimeMinutes * 60UL) * 1000UL;
  unsigned long elapsed = millis() - dryingStartTime;
  if (elapsed >= totalMs) {
    stop_drying_process();
    refresh_drying_ui();
    return;
  }
  int remH = (totalMs - elapsed) / 3600000UL;
  int remMin = ((totalMs - elapsed) % 3600000UL) / 60000UL;
  char ts[16];
  snprintf(ts, 16, "%d:%02d", remH, remMin);
  lv_obj_t *l[] = {objects.trocknungszeit_zeit, objects.trocknungszeit_zeit_1,
                   objects.trocknungszeit_zeit_2, objects.trocknungszeit_zeit_3,
                   objects.trocknungszeit_zeit_4};
  for (auto o : l)
    if (o)
      lv_label_set_text(o, ts);
  if (temperature < (float)dryingTemperature - 0.5f)
    digitalWrite(HEATER_MOSFET_PIN, HIGH);
  else if (temperature > (float)dryingTemperature + 0.5f)
    digitalWrite(HEATER_MOSFET_PIN, LOW);
}

void check_wifi_scan_results() {
  static lv_obj_t *last_scr = nullptr;
  lv_obj_t *curr_scr = lv_scr_act();

  // Auto-start scan once when entering the screen
  if (curr_scr == objects.netzwerksuche_screen && last_scr != curr_scr) {
    WiFi.mode(WIFI_STA);
    WiFi.scanNetworks(true);
    wifiStatusMsg = "Scanning...";
  }
  last_scr = curr_scr;

  int n = WiFi.scanComplete();

  if (n < 0 || !objects.obj0) {
    return;
  }

  lv_obj_clean(objects.obj0);
  if (n == 0) {
    lv_list_add_text(objects.obj0, "No networks found");
    wifiStatusMsg = "No networks";
  } else {
    for (int i = 0; i < n; i++) {
      lv_obj_add_event_cb(
          lv_list_add_btn(objects.obj0, LV_SYMBOL_WIFI, WiFi.SSID(i).c_str()),
          cb_wifi_list_btn, LV_EVENT_CLICKED, nullptr);
    }
    wifiStatusMsg = "Pick a network";
  }
  WiFi.scanDelete();
}

void update_wifi_status_logic() {
  static int lastS = -1;
  int s = WiFi.status();
  if (s != lastS) {
    if (s == WL_CONNECTED) {
      wifiStatusMsg = "Connected";
      wifiConnected = true;
      Serial.printf("WiFi Connected! IP: %s\n",
                    WiFi.localIP().toString().c_str());
      preferences.begin("wifi-config", false);
      preferences.putString("ssid", selectedSSID);
      preferences.putString("password", selectedPassword);
      preferences.end();
    } else if (s == WL_CONNECT_FAILED) {
      wifiStatusMsg = "Wrong password";
      wifiConnected = false;
    } else {
      wifiStatusMsg = "Not connected";
      wifiConnected = false;
    }
    lastS = s;
  }
}

// ============================================================================
// RFID Spool Management – Save/Load spool data linked to RFID card UID
// ============================================================================

// Convert RFID card UID bytes to a short hex string for use as NVS namespace
// Max NVS namespace is 15 chars, so we use max 7 UID bytes (14 hex chars)
static void uid_to_key(byte *uid, byte size, char *out, size_t outLen) {
  out[0] = '\0';
  for (byte i = 0; i < size && (i * 2 + 2) < outLen; i++) {
    char hex[3];
    snprintf(hex, sizeof(hex), "%02X", uid[i]);
    strcat(out, hex);
  }
}

// Check if spool data exists in NVS for a given card UID key
static bool spool_data_exists(const char *nsKey) {
  Preferences p;
  p.begin(nsKey, true); // read-only
  bool exists = p.isKey("material");
  p.end();
  return exists;
}

// Save current spool settings to NVS under the given card UID key
void save_spool_to_rfid_key(const char *nsKey) {
  Preferences p;
  p.begin(nsKey, false); // read-write
  p.putString("material", s_material);
  p.putString("manufacturer", s_hersteller);
  p.putString("colour", s_colour);
  p.putInt("maxWeight", s_maxWeight);
  p.putFloat("weight", filamentWeight);
  p.end();
  Serial.printf("RFID SAVE [%s]: %s / %s / %s / %dg / %.0fg\n", nsKey,
                s_material, s_hersteller, s_colour, s_maxWeight,
                filamentWeight);
}

// Load spool settings from NVS for the given card UID key
static bool load_spool_from_rfid_key(const char *nsKey) {
  Preferences p;
  p.begin(nsKey, true); // read-only
  if (!p.isKey("material")) {
    p.end();
    return false;
  }
  String mat = p.getString("material", "PLA");
  String mfr = p.getString("manufacturer", "Prusament");
  String col = p.getString("colour", "Galaxy Black");
  int mw = p.getInt("maxWeight", 1000);
  float wt = p.getFloat("weight", 0.0);
  p.end();

  strncpy(s_material, mat.c_str(), 31);
  s_material[31] = '\0';
  strncpy(s_hersteller, mfr.c_str(), 31);
  s_hersteller[31] = '\0';
  strncpy(s_colour, col.c_str(), 31);
  s_colour[31] = '\0';
  s_maxWeight = mw;
  // Note: filamentWeight comes from the live scale, but we store the last
  // known weight for reference. We don't overwrite filamentWeight from NVS
  // because the scale gives the real-time value.

  Serial.printf("RFID LOAD [%s]: %s / %s / %s / %dg (saved wt: %.0fg)\n", nsKey,
                s_material, s_hersteller, s_colour, s_maxWeight, wt);
  return true;
}

// Last scanned UID to prevent repeated triggers while card stays on reader
static byte lastUID[10] = {0};
static byte lastUIDSize = 0;
static unsigned long lastRfidScan = 0;
static unsigned long lastRfidAction = 0; // Cooldown after processing a card

void rfid_check_and_handle() {
  // Only check every 500ms to avoid hammering SPI
  if (millis() - lastRfidScan < 500)
    return;
  lastRfidScan = millis();

  // Cooldown: ignore all cards for 3 seconds after last action
  if (millis() - lastRfidAction < 3000)
    return;

  if (!isRfidReady)
    return;

  // Halt any previous card first to reset communication
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  // Try to detect card (3 attempts)
  bool newCard = false;
  for (int attempt = 0; attempt < 3; attempt++) {
    if (rfid.PICC_IsNewCardPresent()) {
      newCard = true;
      break;
    }
    delayMicroseconds(500);
  }
  if (!newCard)
    return;

  // Try reading the serial (3 attempts)
  bool readOk = false;
  for (int attempt = 0; attempt < 3; attempt++) {
    if (rfid.PICC_ReadCardSerial()) {
      readOk = true;
      break;
    }
    delayMicroseconds(500);
  }

  Serial.println("RFID: Card present! Reading serial...");
  if (!readOk) {
    Serial.println("RFID: Failed to read card serial");
    return;
  }

  // Got a card! Convert UID to namespace key
  char nsKey[16];
  uid_to_key(rfid.uid.uidByte, rfid.uid.size, nsKey, sizeof(nsKey));

  Serial.printf("RFID Card detected: %s (size=%d)\n", nsKey, rfid.uid.size);

  // Start cooldown
  lastRfidAction = millis();

  // Try to load data for this card
  if (spool_data_exists(nsKey)) {
    // Card has saved data → LOAD it
    load_spool_from_rfid_key(nsKey);

    // Erase the old data so next tap will SAVE new data
    Preferences p;
    p.begin(nsKey, false);
    p.clear();
    p.end();
    Serial.printf("RFID ERASE [%s]: Old data cleared after loading\n", nsKey);

    // Update all UI elements
    refresh_home_labels();
    refresh_all_bars();
    add_to_history();

    // Show confirmation popup
    char msg[128];
    snprintf(msg, sizeof(msg),
             "Loaded:\n%s  %s\n%s\nWeight: %dg\n(Card cleared)", s_hersteller,
             s_material, s_colour, s_maxWeight);
    lv_obj_t *mbox = lv_msgbox_create(NULL, "Spool Loaded", msg, NULL, true);
    lv_obj_center(mbox);

    // Update E-Paper
    trigger_epaper_update();
  } else {
    // No data on card → SAVE current spool data to it
    save_spool_to_rfid_key(nsKey);

    // Show confirmation popup
    char msg[128];
    snprintf(msg, sizeof(msg), "Saved:\n%s  %s\n%s\nWeight: %dg", s_hersteller,
             s_material, s_colour, s_maxWeight);
    lv_obj_t *mbox = lv_msgbox_create(NULL, "Spool Saved", msg, NULL, true);
    lv_obj_center(mbox);

    // Update E-Paper
    trigger_epaper_update();
  }

  // Release the card
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

// Public wrappers
void save_spool_to_rfid() {
  if (lastUIDSize > 0) {
    char nsKey[16];
    uid_to_key(lastUID, lastUIDSize, nsKey, sizeof(nsKey));
    save_spool_to_rfid_key(nsKey);
  }
}

void load_spool_from_rfid() {
  if (lastUIDSize > 0) {
    char nsKey[16];
    uid_to_key(lastUID, lastUIDSize, nsKey, sizeof(nsKey));
    if (load_spool_from_rfid_key(nsKey)) {
      refresh_home_labels();
      refresh_all_bars();
    }
  }
}

// ============================================================================
// General Filament Data Persistence (without RFID)
// ============================================================================
void save_filament_data() {
  Preferences p;
  p.begin("filament", false);
  p.putString("material", s_material);
  p.putString("manufacturer", s_hersteller);
  p.putString("colour", s_colour);
  p.putInt("maxWeight", s_maxWeight);
  p.end();
  Serial.println("Filament data saved to NVS");
  trigger_epaper_update();
}

void load_filament_data() {
  Preferences p;
  p.begin("filament", true);
  if (p.isKey("material")) {
    String mat = p.getString("material", "PLA");
    String mfr = p.getString("manufacturer", "Prusament");
    String col = p.getString("colour", "Galaxy Black");
    int mw = p.getInt("maxWeight", 1000);
    strncpy(s_material, mat.c_str(), 31);
    s_material[31] = '\0';
    strncpy(s_hersteller, mfr.c_str(), 31);
    s_hersteller[31] = '\0';
    strncpy(s_colour, col.c_str(), 31);
    s_colour[31] = '\0';
    s_maxWeight = mw;
    Serial.println("Filament data loaded from NVS");
  }
  p.end();
}
