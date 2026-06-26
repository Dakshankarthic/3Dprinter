# ESP32-S3 Core Accessories Blueprint

To make your custom motherboard feel exactly like an official ESP32-S3 DevKit, you need the standard physical buttons and the built-in status LED. 

Here is how to wire the **BOOT Button**, the **RESET (EN) Button**, and the **RGB LED (WS2812)** that typically comes on the S3 boards.

---

## 1. RESET (EN) Button
This button manually restarts the ESP32-S3. Even though your USB chip (CP2102N) does auto-reset, having a physical button is crucial if the board freezes or you need to restart without unplugging it.

### Components Needed
*   **1x Push Button:** Tactile Switch (e.g., standard 6x6mm SMD or through-hole) - **Symbol:** `SW_Push`
*   **1x Capacitor:** `1uF` (Size: 0603) *(For debouncing so it resets cleanly)*

### Wiring Steps
1. Connect one side of the push button to the ESP32 **`EN`** pin.
2. Connect the other side of the push button to **`GND`**.
3. Place the **`1uF` capacitor** in parallel with the button (connect one leg to `EN` and the other to `GND`).
4. *(Note: Ensure you already have the **10kΩ pull-up resistor** connecting `EN` to `+3.3V` from Module 4!)*

---

## 2. BOOT Button
This button grounds `IO0`. It performs two vital jobs:
1. If you hold it while pressing RESET, it forces the board into **Firmware Download Mode** (useful if the auto-reset circuit ever fails).
2. When the board is running normally, you can read `IO0` in your code and use this as a **generic physical input button**.

### Components Needed
*   **1x Push Button:** Tactile Switch - **Symbol:** `SW_Push`

### Wiring Steps
1. Connect one side of the push button to ESP32 **`IO0`** (Pin 27).
2. Connect the other side of the push button to **`GND`**.
3. *(Note: `IO0` has an internal pull-up resistor inside the ESP32, so you do NOT need to add an external resistor!)*

---

## 3. DevKit RGB LED (WS2812)
Official ESP32-S3 DevKits have a tiny Neopixel (WS2812B) addressable RGB LED. This is much better than a standard LED because you can make it glow any color (red, green, blue) to indicate different board states (e.g., Red = Error, Green = Heating, Blue = Wi-Fi Connected).

### Components Needed
*   **1x RGB LED:** `WS2812B` (Usually a tiny 2020 or 5050 SMD package) - **Symbol:** `WS2812B`
*   **1x Decoupling Cap:** `100nF` (Size: 0603)

### Wiring Steps
1. **VDD Pin:** Connect to `+3.3V` (and place the `100nF` capacitor from VDD to `GND` right next to the LED).
2. **DIN Pin:** Connect to ESP32 **`IO48`** *(This is the standard DevKit LED pin).*
3. **GND Pin:** Connect to `GND`.
4. **DOUT Pin:** Leave unconnected (unless you want to add a chain of more RGB LEDs!).

---

### How to add to KiCad:
1. Press `A` to add a symbol.
2. Search for **`SW_Push`** for the two buttons.
3. Search for **`WS2812B`** for the RGB LED.
4. Draw the wires as described above!
