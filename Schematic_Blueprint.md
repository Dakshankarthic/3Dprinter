# FilaTrack Motherboard: Master Schematic Blueprint

This document is your step-by-step guide to manually drawing a highly professional, industrial-grade custom ESP32-S3 motherboard schematic. It includes every single resistor, capacitor, and logic chip needed.

---

## **Module 1: The USB Type-C Interface**
This gets power (5V) and data from your computer.

### **Components Needed**
*   **1x Type-C Port:** `Generic 16-pin Type-C` (SMD) - **[LCSC: C165948]**
*   **2x Resistors:** `5.1kΩ` (Size: 0603 SMD) - **[LCSC: C23186]**
*   **1x ESD Protection:** `USBLC6-2SC6` by STMicroelectronics (Package: SOT-23-6) - **[LCSC: C7519]**

### **Wiring Steps**
1. Connect `GND` and `SHIELD` pins on the Type-C port to a `GND` power symbol.
2. Connect `VBUS` pins to a new power label/flag called `+5V_USB`.
3. Connect one **5.1kΩ resistor** between `CC1` and `GND`.
4. Connect the second **5.1kΩ resistor** between `CC2` and `GND`. *(This tells laptop chargers to output 5V).*
5. **ESP Protection (USBLC6-2SC6 6-Pin):** 
    * **Pin 1 (I/O 1 IN)** & **Pin 3 (I/O 2 IN):** Connect to `D+` and `D-` from the Type-C port.
    * **Pin 2 (GND) & Pin 5 (VBUS):** Connect to `GND` and `+5V_USB`.
    * **Pin 6 (I/O 1 OUT)** & **Pin 4 (I/O 2 OUT):** These are the "clean" data lines. Connect them to the `D+` and `D-` pins of your CP2102N chip (Module 2).

---

## **Module 2: The Programmer (CP2102N + Auto-Reset)**
This converts USB data into UART serial data. The **CP2102N (QFN-28)** from Silicon Labs is the definitive, gold-standard industrial choice for the ESP32-S3.

### **Components Needed**
*   **1x Serial IC:** `CP2102N-A02-GQFN28` by Silicon Labs (Package: QFN-28) - **[LCSC: C130489]**
*   **2x Capacitors:** `100nF` **[LCSC: C14663]** & **1x Capacitor:** `4.7uF` **[LCSC: C19666]** (Size: 0603 Ceramic).
*   **2x NPN Transistors:** `S8050` / `MMBT8050` (Package: SOT-23) - **[LCSC: C2146]**
*   **2x Resistors:** `10kΩ` (Size: 0603 SMD) - **[LCSC: C25804]**

### **Wiring Steps**
1. **Powering the Chip (The 3.3V Net):**
   *(The Official DevKit powers this chip from 3.3V, not 5V!)*
   *   Connect **`VREGIN`** (Pin 7) and **`VDD`** (Pin 6) together, and hook them to your `+3.3V` power line.
   *   Place a **100nF capacitor** right on the `VDD` pin going to `GND`.
2. **Detecting the USB Cable (VBUS Pin):**
   *(You must step down the 5V to 3.3V so you don't fry the CP2102N).*
   *   Connect a **22kΩ resistor** from `+5V_USB` to the CP2102N **`VBUS`** (Pin 8).
   *   Connect a **47kΩ resistor** from the CP2102N **`VBUS`** (Pin 8) down to `GND`.
3. **USB Data In:**
   *   Connect the CP2102N **`D+`** to the output `D+` of your ESD Diode.
   *   Connect the CP2102N **`D-`** to the output `D-` of your ESD Diode.
4. **Serial Data Out (The Crossover):**
   *   Connect CP2102N **`TXD`** (Pin 26) to ESP32 **`U0RXD`** (Pin 36). *(Tx goes to Rx)*
   *   Connect CP2102N **`RXD`** (Pin 25) to ESP32 **`U0TXD`** (Pin 37). *(Rx goes to Tx)*
5. **Auto-Reset Circuit (The 2 Transistors):**
    *(This part often causes mistakes, so follow this pin-by-pin!)*
    *   **Transistor 1 (Q1):** 
        *   **Base (Pin 2):** Connect to a **10kΩ resistor**, then to CP2102N `DTR`.
        *   **Emitter (Pin 1):** Connect directly to CP2102N `RTS`.
        *   **Collector (Pin 3):** Connect directly to ESP32 `EN` (CHIP_PU).
    *   **Transistor 2 (Q2):** 
        *   **Base (Pin 2):** Connect to a **10kΩ resistor**, then to CP2102N `RTS`.
        *   **Emitter (Pin 1):** Connect directly to CP2102N `DTR`.
        *   **Collector (Pin 3):** Connect directly to ESP32 `IO0` (Boot).

## **Module 3: Power Supply (5V & 3.3V)**
This section provides clean 5V for the display and 3.3V for the ESP32, both powered from USB.

### **Components Needed**
*   **1x Linear Regulator:** `AMS1117-3.3` (Package: SOT-223) - **[LCSC: C6186]**
*   **2x Capacitors:** `10uF` (Size: 1206 Ceramic) - **[LCSC: C13585]**

### **Wiring Steps**
1. **5V Rail:** Your `+5V_USB` from Module 1 is your `+5V` rail. Use this to power the display and the regulator.
2. **The 3.3V Regulator:**
    *   Connect `+5V_USB` to the `AMS1117-3.3` IN pin. Add a **10uF capacitor** from IN to `GND`.
    *   The AMS1117 OUT pin becomes your `+3.3V` system logic. Add a **10uF capacitor** from OUT to `GND`.
3. **12V for Heater/Fan:** Comes from the separate external 12V supply connected in Module 5 — completely independent from the USB/logic power.

---

## **Module 4: The ESP32-S3 Core**
The brain of the operation: the bare metal WROOM module.

### **Components Needed**
*   **1x MCU Module:** `ESP32-S3-WROOM-1-N16R8` by Espressif - **[LCSC: C3186872]**
*   **3x Decoupling Caps:** `100nF` **[LCSC: C14663]**, `1uF` **[LCSC: C15849]**, `10uF` **[LCSC: C13585]**.
*   **2x Resistors:** `10kΩ` (Size: 0603) - **[LCSC: C25804]**
*   **1x Capacitor:** `1uF` (Size: 0603) - **[LCSC: C15849]**

### **Wiring Steps**
1. Connect `3V3` to `+3.3V` and place your three decoupling capacitors (10uF, 1uF, 100nF) in parallel to `GND`.
2. Connect the large `GND/EPAD` pin squarely to `GND`.
3. Connect `EN` pin to `+3.3V` through a **10kΩ pull-up resistor**, and to `GND` via a **1uF capacitor**.
4. Connect `IO0` (Boot) pin to `+3.3V` through a **10kΩ pull-up resistor**.

---

## **Module 5: Actuator Control (The "Muscle")**
Drives your high-current 12V heater and 12V cooling fan safely using logic-level MOSFETs.

### **Components Needed**
*   **2x MOSFETs:** `AOD4184A` (SMD TO-252) **[LCSC: C148526]** OR `IRLZ44N` (Through-Hole TO-220) **[LCSC: C181057]**.
*   **3x Connectors:** `KF301-2P` (5.08mm Screw Terminals) - **[LCSC: C8451]** *(2 for loads + 1 for 12V input)*
*   **2x Flyback Diodes:** `M7` (SMA SMD diode) - **[LCSC: C6148]**
*   **2x Gate Resistors:** `100Ω` (Size: 0603) - **[LCSC: C22775]**
*   **2x Pull-down Resistors:** `10kΩ` (Size: 0603) - **[LCSC: C25804]**

### **Wiring Steps**
1. **12V Power Input:** Place a dedicated `KF301-2P` screw terminal for your external 12V supply. Connect Terminal Pin 1 to a power label `+12V_IN`. Connect Terminal Pin 2 to `GND`.
2. **Heater (GPIO 7):** ESP32 GPIO7 -> **100Ω Resistor** -> MOSFET 1 Gate. Add a **10kΩ resistor** from the Gate to `GND` (keeps heater off during boot).
3. **Fan (GPIO 38):** ESP32 GPIO38 -> **100Ω Resistor** -> MOSFET 2 Gate. Add a **10kΩ resistor** from the Gate to `GND`. *(GPIO3 is a strapping pin — do NOT use it for the fan!)*
4. **The Most Important Step (Common Ground):** Connect both MOSFET **Sources** (Pin 3) to your main board `GND`. The 12V input connector GND is already tied to this net. *If they do not share a ground, the MOSFETs will not work!*
5. Connect each load terminal's Pin 1 to **`+12V_IN`**. Connect Pin 2 to the respective MOSFET **Drain** (Pin 2).
6. Place an **M7 Diode** across each load terminal (cathode / striped end MUST point towards the `+12V_IN` side).

---

## **Module 6: High-Speed SPI (Displays & RFID)**
Use **Global Labels** for this section so your schematic stays clean instead of a web of crossing lines!

### **Components Needed**
*   **1x Header:** `Conn_01x14` Pin Header (2.54mm pitch, 14-pin) — for TFT + Touch *(matches the module's physical connector for direct plug-in)*
*   **1x Header:** `JST-XH 8-Pin` (2.54mm pitch) - **[LCSC: C144396]** — for E-Paper
*   **1x Header:** `JST-XH 8-Pin` (2.54mm pitch) - **[LCSC: C144396]** — for RFID

### **Wiring Steps**
1. Create **SPI Bus** Global Labels on the ESP32: `SPI_SCK` (GPIO14), `SPI_MOSI` (GPIO13), `SPI_MISO` (GPIO12).
2. Attach these three Global Labels to the corresponding SCK/MOSI/MISO pins on *every* header.
3. **TFT + Touch Header (14-pin):** Create and route the following Global Labels:
    * `TFT_CS` (GPIO4), `TFT_DC` (GPIO9), `TFT_RST` (GPIO15), `TFT_BL` (GPIO11)
    * `TOUCH_CS` (GPIO18), `TOUCH_IRQ` (GPIO21)
    * Plus `SPI_SCK`, `SPI_MOSI`, `SPI_MISO`, `+3.3V` (or 5V), and `GND`.
4. **E-Paper Header (8-pin):** Create and route the following Global Labels:
    * `EPAPER_CS` (GPIO10), `EPAPER_DC` (GPIO16), `EPAPER_RST` (GPIO17), `EPAPER_BUSY` (GPIO8)
    * Plus `SPI_SCK`, `SPI_MOSI`, `+3.3V`, and `GND`. *(No MISO needed for most e-paper displays)*
5. **RFID Header (8-pin):** Create and route the following Global Labels:
    * `RFID_SDA` (GPIO47), `RFID_RST` (GPIO48)
    * Plus `SPI_SCK`, `SPI_MOSI`, `SPI_MISO`, `+3.3V`, and `GND`.

---

## **Module 7: The Sensors & Status LED**
Direct integration of the weight scale, temperature/humidity sensor, and indicator LED.

### **Components Needed**
*   **1x Header:** `Conn_01x04` (2.54mm pitch, 4-pin) — for the external HX711 Module
*   **1x Header:** `Conn_01x03` (2.54mm pitch, 3-pin) — for external DHT22 sensor
*   **1x Pull-up Resistor:** `10kΩ` (Size: 0603, for DHT data line) - **[LCSC: C25804]**
*   **1x LED:** `Green LED` (0603 SMD or 3mm Through-Hole)
*   **1x Resistor:** `330Ω` (Size: 0603, current-limiting for LED) - **[LCSC: C23138]**

### **Wiring Steps**
1. **HX711 Module Header (4-pin):**
    Instead of soldering the bare chip, we use a header to plug in your shop-bought green module.
    * Header Pin 1 (`VCC`) → `+3.3V`
    * Header Pin 2 (`GND`) → `GND`
    * Header Pin 3 (`DT`) → ESP32 **GPIO6**
    * Header Pin 4 (`SCK`) → ESP32 **GPIO5**
    *(The load cell wires will connect directly to the green module itself, NOT this motherboard).*
2. **DHT22 Header (3-pin):** 
    * Header Pin 1 → `+3.3V`
    * Header Pin 2 → ESP32 **GPIO2** (DATA)
    * Header Pin 3 → `GND`
    * Add a **10kΩ pull-up resistor** from Pin 2 (DATA) to `+3.3V` *(solder this on the PCB, not on the sensor)*.
3. **Status LED:**
    * Connect ESP32 **GPIO1** → **330Ω resistor** → LED Anode (+). Connect LED Cathode (−) to `GND`.

---

### **Done!**
Once every module above is drawn in your KiCad schematic, run the **Design Rules Check (DRC)**. When it returns zero errors, you are ready to assign footprints and begin routing the physical PCB!
