// ============================================================================
// epaper.cpp – Waveshare 2.13" e-Paper (B) Three-Color Display Driver
// Shows: Material, Manufacturer, Colour, Weight
// ============================================================================
#include "epaper.h"
#include "board_config.h"
#include "logo_bitmap.h"   // Auto-generated logo bitmap

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>
#include <GxEPD2_3C.h>
#include <lvgl.h>

// Waveshare 2.13" (B) V4 Three-color: 212x104, SSD1680
static GxEPD2_3C<GxEPD2_213_Z98c, GxEPD2_213_Z98c::HEIGHT>
    epaper(GxEPD2_213_Z98c(EPAPER_CS_PIN, EPAPER_DC_PIN, EPAPER_RST_PIN,
                           EPAPER_BUSY_PIN));

static bool epaperReady = false;

void epaper_init() {
  Serial.println("E-Paper initialization sequence starting...");

  // Explicitly set SPI pins for the global object used by GxEPD2
  SPI.begin(DISPLAY_PIN_SCLK, DISPLAY_PIN_MISO, DISPLAY_PIN_MOSI);

  // Initialize the e-Paper driver
  epaper.init(115200, true, 200, false);
  epaper.setRotation(1); // Landscape mode
  epaper.setTextWrap(false);

  // === LOGO SPLASH SCREEN ===
  Serial.println("E-Paper: Showing logo...");
  epaper.setFullWindow();
  epaper.firstPage();
  do {
    epaper.fillScreen(GxEPD_WHITE);
    // Draw black channel of logo
    epaper.drawBitmap(0, 0, logo_bw, LOGO_WIDTH, LOGO_HEIGHT, GxEPD_BLACK);
    // Draw red channel of logo (spool filament = red!)
    epaper.drawBitmap(0, 0, logo_red, LOGO_WIDTH, LOGO_HEIGHT, GxEPD_RED);
    lv_timer_handler();
  } while (epaper.nextPage());

  epaperReady = true;
  Serial.println("E-Paper initialized (2.13\" three-color)");
}


void epaper_update_spool(const char *material, const char *manufacturer,
                         const char *colour, float weight, int maxWeight) {
  if (!epaperReady)
    return;

  Serial.printf("E-Paper updating: %s / %s / %s / %.0fg / %dg\n", material,
                manufacturer, colour, weight, maxWeight);

  // Full update for clear three-color rendering
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

    lv_timer_handler(); // Keep Main UI alive while e-paper is refreshing
  } while (epaper.nextPage());

  Serial.println("E-Paper update complete");
}

void epaper_clear() {
  if (!epaperReady)
    return;
  epaper.setFullWindow();
  epaper.firstPage();
  do {
    epaper.fillScreen(GxEPD_WHITE);
    lv_timer_handler();
  } while (epaper.nextPage());
  Serial.println("E-Paper cleared");
}
