#ifndef BUTTON_FUNCTIONS_H
#define BUTTON_FUNCTIONS_H

#include "screens.h"
#include "ui.h"
#include <MFRC522.h>
#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// ── Global state variables (defined in main.cpp) ─────────────────────────────
extern bool isDryingActive;
extern bool isAutoMode;
extern char selectedSSID[33];
extern int calibrationWeight;
extern int currentCalibrationSelection;
extern float filamentWeight;
extern float temperature;
extern float humidity;
extern bool wifiConnected;
extern bool isScaleReady;
extern bool isDhtReady;
extern bool isRfidReady;
extern MFRC522 rfid;
extern int selectedMaterial;
extern int selectedManufacturer;
extern int selectedColor;
extern int dryingTimeHours;
extern int dryingTimeMinutes;
extern int dryingTemperature;
extern int fanSpeed;

// ── Utility functions
// ─────────────────────────────────────────────────────────
void update_ui_sensor_data();
void update_homescreen_filament_info();
void update_homescreen_weight();
void force_update_homescreen_filament_info();

// ── Drying control
// ────────────────────────────────────────────────────────────
void start_drying_process();
void stop_drying_process();
void control_drying_process();

// ── Persistence
// ───────────────────────────────────────────────────────────────
void save_filament_data();
void load_filament_data();

// ── RFID Spool Management
// ─────────────────────────────────────────────────────────────
void rfid_check_and_handle(); // Call from loop() to detect card taps
void save_spool_to_rfid();   // Save current spool info to the detected card UID
void load_spool_from_rfid(); // Load spool info from the detected card UID

// ── Wi-Fi
// ─────────────────────────────────────────────────────────────────────
void check_wifi_scan_results();
void update_wifi_status_logic();
void tare_scale();
void calibrate_scale(int known_weight_g);

// ── Button / colour setup (called once from main after ui_init)
// ───────────────
void setup_color_buttons();

// ── E-Paper
void trigger_epaper_update();

#ifdef __cplusplus
}
#endif

#endif // BUTTON_FUNCTIONS_H
