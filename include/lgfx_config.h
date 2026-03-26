#ifndef LGFX_CONFIG_H
#define LGFX_CONFIG_H

#include "board_config.h"
#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device {
public:
  lgfx::Bus_SPI _bus_instance;
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_XPT2046 _touch_instance;

  LGFX(void) {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = DISPLAY_SPI_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = DISPLAY_SPI_FREQ;
      cfg.pin_sclk = DISPLAY_PIN_SCLK;
      cfg.pin_mosi = DISPLAY_PIN_MOSI;
      cfg.pin_miso = DISPLAY_PIN_MISO;
      cfg.pin_dc = DISPLAY_PIN_DC;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs = DISPLAY_PIN_CS;
      cfg.pin_rst = DISPLAY_PIN_RST;
      cfg.pin_busy = -1;
      cfg.panel_width = 320;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.bus_shared = true;
      cfg.rgb_order = false; // Changed for SPI2_HOST compatibility
      cfg.memory_width = 320;
      cfg.memory_height = 480;
      cfg.readable = false;
      cfg.invert = false;     // ST7796 does NOT need inversion
      cfg.dlen_16bit = false; // FIXED: was true, garbled SPI commands!
      _panel_instance.config(cfg);
    }

    {
      auto cfg = _light_instance.config();
      cfg.pin_bl = DISPLAY_PIN_BL;
      cfg.invert = false;
      cfg.freq = 1000;
      cfg.pwm_channel = 7;
      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);
    }

    // Touch controller configuration for XPT2046 (SPI) - SHARED BUS
    {
      auto cfg = _touch_instance.config();
      cfg.x_min = 3900;
      cfg.x_max = 200;
      cfg.y_min = 200;
      cfg.y_max = 3900;
      cfg.pin_int = -1;
      cfg.bus_shared = true;
      cfg.offset_rotation = 2;
      cfg.spi_host = TOUCH_SPI_HOST;
      cfg.freq = 2500000;
      cfg.pin_sclk = TOUCH_PIN_SCLK;
      cfg.pin_mosi = TOUCH_PIN_MOSI;
      cfg.pin_miso = TOUCH_PIN_MISO;
      cfg.pin_cs = TOUCH_PIN_CS;

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance);
    }

    setPanel(&_panel_instance);
  }

  void setBacklight(uint8_t brightness) {
    _light_instance.setBrightness(brightness);
  }

  bool initDisplay() {
    if (!init()) {
      return false;
    }

    setRotation(1);
    setSwapBytes(true);
    setBacklight(200);
    fillScreen(TFT_BLACK);

    return true;
  }

  bool getTouchRaw(uint16_t *x, uint16_t *y) {
    lgfx::touch_point_t tp[1];
    if (_touch_instance.getTouchRaw(tp, 1)) {
      if (x) {
        *x = tp[0].x;
      }
      if (y) {
        *y = tp[0].y;
      }
      return true;
    }
    return false;
  }

  bool testTouch() {
    uint16_t x, y;
    bool touched = getTouch(&x, &y);
    if (touched) {
      Serial.printf("Touch detected: X=%d, Y=%d\n", x, y);
      return true;
    }
    return false;
  }

  void debugTouchController() {
    Serial.println("=== Touch Controller Debug ===");
    Serial.printf("Touch controller type: XPT2046 (SPI) - SHARED BUS\n");
    Serial.printf("Touch pins: CS=%d, IRQ=%d\n", TOUCH_PIN_CS, TOUCH_PIN_IRQ);
    Serial.printf("SPI pins: SCLK=%d, MOSI=%d, MISO=%d (SHARED with display)\n",
                  TOUCH_PIN_SCLK, TOUCH_PIN_MOSI, TOUCH_PIN_MISO);
    Serial.println("===============================");
  }
};

#endif