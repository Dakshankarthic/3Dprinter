# FilaTrack — Full Project Documentation

**FilaTrack** is a filament tracking and drying system for 3D printing, built on an ESP32-S3 with a touch display, RFID spool identification, e-paper status display, and web API. This document describes the architecture, hardware, software, and usage.

---

## Table of Contents

1. [Project Overview](#1-project-overview)
2. [Hardware Requirements](#2-hardware-requirements)
3. [Pin Configuration](#3-pin-configuration)
4. [Project Structure](#4-project-structure)
5. [Software Architecture](#5-software-architecture)
6. [Setup & Installation](#6-setup--installation)
7. [Configuration](#7-configuration)
8. [User Interface](#8-user-interface)
9. [API Reference](#9-api-reference)
10. [Drying Presets](#10-drying-presets)
11. [RFID Spool Management](#11-rfid-spool-management)
12. [Development Notes](#12-development-notes)
13. [Troubleshooting](#13-troubleshooting)

---

## 1. Project Overview

FilaTrack provides:

| Feature | Description |
|---------|-------------|
| **Weight measurement** | HX711 load cell amplifier for filament weight tracking |
| **Temperature/humidity** | DHT11 sensor for drying chamber monitoring |
| **RFID spool identification** | MFRC522 to read/write spool data on RFID cards |
| **Heater & fan control** | MOSFET + PWM for drying temperature control |
| **Touch UI** | LVGL-based interface (German language) on 320×480 TFT |
| **E-Paper display** | Waveshare 2.13" three-color for spool info at a glance |
| **WiFi & Web API** | Remote status and control via HTTP |
| **NVS persistence** | WiFi credentials, scale calibration, spool settings stored in flash |

---

## 2. Hardware Requirements

| Component | Specification |
|-----------|---------------|
| **MCU** | ESP32-S3 N16R8 (16 MB Flash, 8 MB Octal PSRAM) |
| **Main display** | 320×480 TFT (ST7796) on SPI2 (30 MHz) |
| **Touch controller** | XPT2046 (shared SPI2 with display) |
| **E-Paper** | Waveshare 2.13" B three-color (GDEY0213Z98 / SSD1680) |
| **Load cell amplifier** | HX711 |
| **Temperature/humidity** | DHT11 |
| **RFID** | MFRC522 |
| **Actuators** | Heater MOSFET, fan with PWM (25 kHz, 8-bit) |
| **Status LED** | GPIO 1 |

---

## 3. Pin Configuration

All pin assignments are defined in `include/board_config.h`. Use this file to adapt the project to different hardware.

### Display & Touch (shared SPI2)

| Signal | GPIO | Notes |
|--------|------|-------|
| SCLK | 14 | Display + Touch |
| MOSI | 13 | Display + Touch |
| MISO | 12 | Display + Touch |
| Display CS | 4 | |
| Display DC | 9 | |
| Display RST | 15 | |
| Display BL | 11 | Backlight PWM |
| Touch CS | 18 | |
| Touch IRQ | 21 | |

### E-Paper (shared SPI bus)

| Signal | GPIO |
|--------|------|
| CS | 10 |
| DC | 16 |
| RST | 17 |
| BUSY | 8 |

### RFID (MFRC522)

| Signal | GPIO |
|--------|------|
| SDA | 47 |
| RST | 48 |

### Sensors

| Sensor | GPIO |
|--------|------|
| HX711 SCK | 5 |
| HX711 DOUT | 6 |
| DHT11 Data | 2 |

### Actuators & Status

| Signal | GPIO | Notes |
|--------|------|-------|
| Heater MOSFET | 7 | Digital output |
| Fan PWM | 3 | 25 kHz, 8-bit duty |
| LED | 1 | Heartbeat indicator |

---

## 4. Project Structure

```
d:\finial 3D 14022026 -27022026-----\
├── platformio.ini              # PlatformIO configuration
├── custom_partitions.csv       # ESP32 flash partition table
├── DOCUMENTATION.md            # This file
├── README.md                   # Project overview (legacy)
├── .vscode/
│   ├── launch.json
│   ├── extensions.json
│   ├── c_cpp_properties.json
│   └── settings.json
├── include/
│   ├── board_config.h          # Pin assignments, hardware config
│   ├── lgfx_config.h           # LovyanGFX display/touch (ST7796, XPT2046)
│   └── lv_conf.h               # LVGL configuration
├── src/
│   ├── main.cpp                # Entry point, hardware init, main loop
│   ├── epaper.h / epaper.cpp   # E-Paper display driver (GxEPD2)
│   └── ui/
│       ├── button_functions.cpp/.h  # UI callbacks, drying, RFID, WiFi, calibration
│       ├── screens.h / screens.c    # LVGL screen definitions (EEZ Studio)
│       ├── ui.h / ui.c              # LVGL UI init, assets
│       ├── eez-flow.h / eez-flow.cpp # EEZ Studio flow engine
│       ├── structs.h, vars.h, actions.h
│       ├── styles.h, styles.c
│       ├── images.h, images.c
│       ├── fonts.h
│       └── ui_image_*.c              # Embedded UI images
├── lib/
│   └── LovyanGFX-master/       # Local LovyanGFX fork (optional)
└── data/                       # SPIFFS data directory (for file system)
```

### Flash Partitions (`custom_partitions.csv`)

| Partition | Type | Size |
|-----------|------|------|
| nvs | data | 20 KB |
| otadata | data | 8 KB |
| app0 | app | 5 MB |
| spiffs | data | 2 MB |

---

## 5. Software Architecture

### Entry Point: `src/main.cpp`

1. **Setup:**
   - Initializes heater (digital) and fan (PWM)
   - Initializes display and touch via LovyanGFX (ST7796 + XPT2046) using SPI2
   - Initializes HX711 (load cell), DHT11, MFRC522 (RFID)
   - Loads scale calibration factor and WiFi credentials from NVS
   - Initializes LVGL with **PSRAM-backed buffers** (~80 lines, 150KB)
   - Loads UI, color buttons, filament data
   - Starts WiFi, web server, and e-paper (shows **startup logo**)

2. **Main loop (approx. every 5 ms):**
   - `lv_timer_handler()` — LVGL refresh
   - `check_wifi_scan_results()` — WiFi scan updates
   - `update_wifi_status_logic()` — Connection status
   - `server.handleClient()` — Web requests
   - Every 1 s: sensor reads (HX711, DHT11), RFID check, drying control, UI updates
   - LED heartbeat (1 s period)

### Weight Measurement

- Median filter (5 samples) to reduce electrical spikes
- EMA filter (0.5 / 0.5) for fast yet smooth display
- Deadzone < 10 g with 5 g rounding for rock-solid stability
- Calibration factor stored in NVS (`scale-init` namespace)

### Key Modules

| Module | Path | Purpose |
|--------|------|---------|
| E-Paper | `epaper.cpp` | GxEPD2 driver; shows **3-color startup logo**, then spool info (material, mfr, color, weight) |
| Button logic | `button_functions.cpp` | Material/manufacturer/color, drying, WiFi, RFID, scale calibration |
| UI / screens | `ui.c`, `screens.c` | LVGL screens generated by EEZ Studio |
| Display | `lgfx_config.h` | ST7796 panel, XPT2046 touch, shared SPI2 |

---

## 6. Setup & Installation

### Prerequisites

- [PlatformIO](https://platformio.org/) (IDE or CLI)
- ESP32-S3 board with USB connection

### Build

```bash
pio run
# or explicitly:
pio run -e esp32s3
```

### Upload Firmware

```bash
pio run -t upload
```

### Serial Monitor (115200 baud)

```bash
pio device monitor
# or
pio run -t monitor
```

### Upload SPIFFS (if using file system)

```bash
pio run -t uploadfs
```

---

## 7. Configuration

### WiFi

WiFi credentials are stored in NVS under namespace `wifi-config`:

- `ssid` — Network name  
- `password` — Network password  

Configure via the **Settings → WLAN** screen in the UI; no hardcoded credentials.

### Scale Calibration

- Factor stored in NVS (`scale-init`, key `factor`)
- Default factor: `226.0`
- Calibrate via UI: long-press the 1000 g preset button with a known weight on the scale

### Debug Serial Output

In `platformio.ini`, uncomment:

```ini
; -DDEBUG_SERIAL
```

to enable additional serial logging (increases flash usage).

---

## 8. User Interface

### Language

The UI is in German.

### Screens

| Screen | German Name | Purpose |
|--------|-------------|---------|
| Home | Home | Main navigation, weight, temp, humidity |
| New Spool | Neue Spule | Material → Manufacturer → Color selection |
| Drying | Trocknen | Start/stop drying, presets, timer |
| Settings | Einstellungen | WiFi, calibration, system data, spool data |

### Navigation Buttons

- **Neue Spule** — New spool (material/manufacturer/color)
- **Trocknen** — Drying control
- **Einstellungen** — Settings
- **Home** — Return to home
- **Zurück** — Back
- **Abbruch** — Cancel

### Drying Control

- **Start** — Begin drying
- **Stop** — Stop drying
- **Presets** — PLA, PETG, ABS, TPU (temperature and time)
- **Auto mode** — Optional automatic control

---

## 9. API Reference

### E-Paper API (`epaper.h`)

```c
void epaper_init();
void epaper_update_spool(const char *material, const char *manufacturer,
                         const char *colour, float weight, int maxWeight);
void epaper_clear();
```

### Web API

When WiFi is connected, the device serves HTTP on port 80.

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/` | GET | HTML status page (IP, title) |
| `/api/status` | GET | JSON: `weight`, `temperature`, `humidity`, `drying`, `targetTemp`, `timeH`, `timeM` |
| `/api/control` | GET | Control drying: `?drying=on` or `?drying=off`; returns status JSON |

### Button Functions API (`button_functions.h`)

| Function | Purpose |
|----------|---------|
| `update_ui_sensor_data()` | Refresh sensor values on UI |
| `start_drying_process()` | Start drying |
| `stop_drying_process()` | Stop drying |
| `control_drying_process()` | Called from loop; handles heater/fan logic |
| `save_filament_data()` / `load_filament_data()` | NVS persistence for spool settings |
| `rfid_check_and_handle()` | Detect card tap, load or save spool |
| `save_spool_to_rfid()` / `load_spool_from_rfid()` | RFID read/write |
| `check_wifi_scan_results()` | Process WiFi scan |
| `tare_scale()` | Zero the scale |
| `calibrate_scale(int known_weight_g)` | Calibrate with known weight |
| `trigger_epaper_update()` | Refresh e-paper with current spool info |

---

## 10. Drying Presets

| Preset | Temperature | Time |
|--------|-------------|------|
| PLA | 45°C | 5 h |
| PETG | 65°C | 6 h |
| ABS | 75°C | 6 h |
| TPU | 55°C | 8 h |

Custom temperature and time can be set in the drying screen.

---

## 11. RFID Spool Management

### Card with Stored Data

When a card with previously saved spool data is tapped:

- Spool is loaded from NVS
- Popup shows loaded info
- E-paper is updated
- Stored data is cleared from the card

### Card without Data

When an empty/writable card is tapped:

- Current spool (material, manufacturer, color, weight) is saved to NVS
- Data is written to the RFID card
- Confirmation is shown

---

## 12. Development Notes

### README vs Actual Hardware

The legacy `README.md` refers to ILI9341; the current hardware uses **ST7796** 320×480 and pins from `board_config.h`. Use `board_config.h` and this documentation as the source of truth.

### EEZ Studio

UI layouts are created in [EEZ Studio](https://github.com/eez-open/studio). Regenerate `eez-flow`, `screens`, and assets when the UI changes.

### SPI Sharing

Display, touch, RFID, and e-paper share SPI. `epaper.cpp` assumes SPI is already initialized. Timing and bus coordination are important; avoid concurrent SPI access.

### MQTT

The README mentions MQTT, but `PubSubClient` is commented out in `platformio.ini`. MQTT is not active in the current build.

### Library Dependencies

| Library | Version | Purpose |
|---------|---------|---------|
| LovyanGFX | ^1.2.7 | Display and touch |
| Adafruit BusIO | ^1.15.0 | I2C/SPI helpers |
| DHT sensor library | ^1.4.6 | DHT11 |
| DallasTemperature | ^3.11.0 | Optional DS18B20 |
| HX711 | ^0.7.5 | Load cell |
| Adafruit GFX Library | ^1.11.9 | Graphics |
| MFRC522 | ^1.4.10 | RFID |
| lvgl | ^8.3.11 | GUI |
| GxEPD2 | ^1.5.8 | E-Paper |

---

## 13. Troubleshooting

| Issue | Possible Cause | Action |
|-------|----------------|--------|
| Display not working | Pin connections, SPI config | Check `board_config.h` and wiring; verify ST7796 and LovyanGFX settings |
| Touch not responding | Wrong pins, calibration | Check touch CS and IRQ; verify XPT2046 config in `lgfx_config.h` |
| Sensors not reading | Wiring, pin assignment | Verify HX711 (5/6), DHT11 (2), MFRC522 (47/48) |
| WiFi connection failed | Wrong credentials | Reconfigure via Settings → WLAN |
| Scale unstable / wrong | Calibration, load | Recalibrate with known weight; check for mechanical vibration |
| E-paper not updating | SPI conflicts | Ensure display/touch init before e-paper; avoid overlapping SPI use |

### Serial Debug

Use 115200 baud. Enable `DEBUG_SERIAL` in `platformio.ini` for more verbose output.

---

## License

This project is open source. See the project repository for license details.

---

*Last updated: March 2026*
