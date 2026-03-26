# FilaTrack ESP32-S3 N16R8 Project

This project implements a filament tracking and drying system using an ESP32-S3 N16R8 board with a touchscreen display.

## Hardware Requirements

- ESP32-S3 N16R8 board (16MB Flash, 8MB PSRAM)
- ILI9341 320x240 TFT Display with Touch
- HX711 Load Cell Amplifier
- MFRC522 RFID Reader
- DHT11 Temperature/Humidity Sensor
- MOSFETs for Heater and Fan control
- Load Cell for Weight Measurement

## Pin Configuration

### Display (ILI9341)
- SCLK: GPIO 18
- MOSI: GPIO 23
- MISO: GPIO 19
- CS: GPIO 5
- DC: GPIO 2
- RST: GPIO 15
- BL: GPIO 4

### Touch (XPT2046)
- CS: GPIO 16
- IRQ: GPIO 21

### Sensors
- HX711 SCK: GPIO 5
- HX711 DOUT: GPIO 4
- DHT11: GPIO 13
- RFID SDA: GPIO 22
- RFID RST: GPIO 21

### Control Outputs
- Heater MOSFET: GPIO 16
- Fan MOSFET: GPIO 17

## Software Features

### UI System
- LVGL-based touch interface
- Multiple screens for different functions
- German language interface
- Touch-responsive buttons and controls

### Main Functions
- **Home Screen**: Main navigation hub
- **New Spool**: Add new filament spool (Material → Manufacturer → Color)
- **Drying**: Control filament drying process with presets
- **Settings**: WiFi, calibration, system data, spool data

### Hardware Integration
- Weight measurement with HX711
- Temperature/humidity monitoring with DHT11
- RFID tag reading for spool identification
- Heater and fan control for drying
- WiFi connectivity for remote monitoring
- MQTT data publishing

## Setup Instructions

1. **Install PlatformIO**: Make sure PlatformIO is installed in your IDE

2. **Configure WiFi**: Update the WiFi credentials in `src/main.cpp`:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   const char* mqtt_server = "YOUR_MQTT_SERVER_IP";
   ```

3. **Calibrate Scale**: Update the scale calibration factor in `src/main.cpp`:
   ```cpp
   scale.set_scale(2280.0); // Replace with your calibrated value
   ```

4. **Build and Upload**: Use PlatformIO to build and upload the project to your ESP32-S3 board

## Button Functions

### Navigation Buttons
- **Neue Spule**: Navigate to material selection screen
- **Trocknen**: Navigate to drying control screen
- **Einstellungen**: Navigate to settings screen
- **Home**: Return to home screen
- **Zurück**: Go back to previous screen
- **Abbruch**: Cancel current operation

### Drying Control
- **Start**: Begin drying process
- **Stop**: Stop drying process
- **Preset Selection**: Choose drying parameters (PLA, ABS, PETG, Custom)

### Settings
- **WLAN**: WiFi configuration
- **Kalibrierung**: Scale calibration
- **Systemdaten**: System information
- **Spulen Daten**: Spool data management

## MQTT Topics

The system publishes data to the following MQTT topics:
- `filatrack/data/temperature`: Current temperature
- `filatrack/data/humidity`: Current humidity
- `filatrack/data/weight`: Current filament weight

## Troubleshooting

### Common Issues

1. **Display not working**: Check pin connections and SPI configuration
2. **Touch not responding**: Verify touch pin connections
3. **Sensors not reading**: Check sensor wiring and pin assignments
4. **WiFi connection failed**: Verify SSID and password
5. **MQTT not connecting**: Check server IP and network connectivity

### Debug Information

Enable serial output at 115200 baud to see debug messages and system status.

## Customization

### Adding New Materials
Edit the material selection screens in the UI to add new filament types.

### Modifying Drying Presets
Update the drying preset values in `src/ui/actions.cpp`:
```cpp
void action_trocknung_preset_selected(int preset_id) {
    // Modify temperature and time values here
}
```

### Changing Pin Assignments
Update pin definitions in `include/board_config.h` to match your hardware setup.

## License

This project is open source. Please check the license file for details.

## Support

For issues and questions, please check the documentation or create an issue in the project repository.






















