#ifndef EPAPER_H
#define EPAPER_H

#include <Arduino.h>

// Initialize the e-Paper display
void epaper_init();

// Update e-Paper with current spool info
// Call this after spool data changes (RFID load, UI selection, etc.)
void epaper_update_spool(const char *material, const char *manufacturer,
                         const char *colour, float weight, int maxWeight);

// Clear the e-Paper display
void epaper_clear();

#endif // EPAPER_H
