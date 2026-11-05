#ifndef EPAPER_H
#define EPAPER_H

#include <Arduino.h>

// Initialize the e-Paper display
void epaper_init();

// Request debounced update with current spool info
// Non-blocking: waits for user idle (2.5s) before refreshing to prevent UI freeze
void epaper_request_update(const char *material, const char *manufacturer,
                          const char *colour, float weight, int maxWeight);

// Direct / immediate update
void epaper_update_spool(const char *material, const char *manufacturer,
                         const char *colour, float weight, int maxWeight);

// Check & perform pending e-paper update in loop()
void epaper_tick();

// True if e-paper update is currently pending or drawing
bool epaper_is_busy();

// Clear the e-Paper display
void epaper_clear();

#endif // EPAPER_H
