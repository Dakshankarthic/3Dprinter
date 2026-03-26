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
*   **3x Capacitors:** `100nF` **[LCSC: C14663]** & `4.7uF` **[LCSC: C19666]** (Size: 0603 Ceramic).
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
4. **Auto-Reset Circuit (The 2 Transistors):**
    *(This part often causes mistakes, so follow this pin-by-pin!)*
    *   **Transistor 1 (Q1):** 
        *   **Base (Pin 2):** Connect to a **10kΩ resistor**, then to CP2102N `DTR`.
        *   **Emitter (Pin 1):** Connect directly to CP2102N `RTS`.
        *   **Emitter (Pin 1)::** Connect directly to CP2102N `RTS`.
        *   **Collector (Pin 3):** Connect directly to ESP32 `EN` (CHIP_PU).
    *   **Transistor 2 (Q2):** 
        *   **Base (Pin 2):** Connect to a **10kΩ resistor**, then to CP2102N `RTS`.
        *   **Emitter (Pin 1):** Connect directly to CP2102N `DTR`.
        *   **Collector (Pin 3):** Connect directly to ESP32 `IO0` (Boot).

## **Module 3: Logic Power & Battery Charging**
This section manages your pure 5V logic power via USB, charges the backup 3.7V Lithium battery, and provides clean 3.3V for the ESP32. *(The big 12V heater runs totally separately)*

### **Components Needed**
*   **1x Battery IC:** `TP4056` (1A Li-Ion Charger) - **[LCSC: C16581]**
*   **1x Linear Regulator:** `AMS1117-3.3` (Package: SOT-223) - **[LCSC: C6186]**
*   **1x Battery Connector:** `Conn_01x02` (Generic 2-pin header for LiPo) - **[LCSC: C135439]**
*   **2x Capacitors:** `10uF` (Size: 1206 Ceramic) - **[LCSC: C13585]**
*   **1x Resistor:** `1.2kΩ` (Programs the TP4056 to charge at 1A) - **[LCSC: C22787]**
*   **2x Schottky Diodes:** `SS34` (Prevents power backfeeding) - **[LCSC: C8678]**

### **Wiring Steps**
1. **The Charger Input:** Connect `+5V_USB` to TP4056 Pin 4 (`VCC`) and Pin 8 (`CE`). 
    *   **The Capacitor:** Connect one leg of a **10uF Capacitor** to `+5V_USB` (right next to Pin 4), and the other leg to `GND`.
2. **Programming the Charger:** Connect TP4056 Pin 2 (`PROG`) to a **1.2kΩ resistor** leading to `GND`. Connect Pin 1 and 3 to `GND`.
3. **The Battery Connection:** 
    *   Connect your 2-pin battery connector's Positive terminal to TP4056 Pin 5 (`BAT`). Connect the Negative to `GND`. 
    *   Add a **10uF Capacitor** from `BAT` to `GND`. Label the `BAT` line `+3.7V_BAT`.
4. **The 3.3V Regulator:**
    *   Connect both `+5V_USB` and `+3.7V_BAT` into the `AMS1117-3.3` IN pin using two Schottky diodes (to prevent the battery driving power backwards into the USB port).
    *   The AMS1117 OUT pin becomes your `+3.3V` system logic. Add a **10uF capacitor** from IN to GND, and OUT to GND.

---

## **Module 4: The EPS32-S3 Core**
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
*   **2x Connectors:** `KF301-2P` (5.08mm Screw Terminals) - **[LCSC: C8451]**
*   **2x Flyback Diodes:** `M7` (SMA SMD diode) - **[LCSC: C6148]**
*   **2x Gate Resistors:** `100Ω` (Size: 0603) - **[LCSC: C22775]**
*   **2x Pull-down Resistors:** `10kΩ` (Size: 0603) - **[LCSC: C25804]**

### **Wiring Steps**
1. **Heater (GPIO 7):** ESP32 Pin 7 -> **100Ω Resistor** -> MOSFET 1 Gate. Add a **10kΩ resistor** from the Gate to `GND` (keeps heater off during boot).
2. **Fan (GPIO 3):** ESP32 Pin 3 -> **100Ω Resistor** -> MOSFET 2 Gate. Add a **10kΩ resistor** from the Gate to `GND`.
3. **The Most Important Step (Common Ground):** Connect both MOSFET **Sources** (Pin 3) to your main board `GND`. Also connect the negative/GND pin of your separate 12V power supply directly to this `GND` symbol. *If they do not share a ground, the MOSFETs will not work!*
4. Connect Terminal Pin 1 to your separate **`12V_IN`**. Connect Terminal Pin 2 to MOSFET **Drain** (Pin 2).
5. Place the **M7 Diode** completely across the Terminal pins (The cathode / striped end MUST point towards the `12V_IN` side).

---

## **Module 6: High-Speed SPI (Displays & RFID)**
Use **Global Labels** for this section so your schematic stays clean instead of a web of crossing lines!

### **Components Needed**
*   **1x Header:** `JST-XH 10-Pin` (2.54mm pitch) - **[LCSC: C144395]**
*   **2x Headers:** `JST-XH 8-Pin` (2.54mm pitch) - **[LCSC: C144396]**

### **Wiring Steps**
1. Create Global Labels on the ESP32: `SPI_SCK` (GPIO14), `SPI_MOSI` (GPIO13), `SPI_MISO` (GPIO12).
2. Attach these three Global Labels to the corresponding SCK/MOSI/MISO pins on *every* header.
3. Create CS (Chip Select) Labels on the ESP32: `TFT_CS` (GPIO4), `TOUCH_CS` (GPIO18), `EPAPER_CS` (GPIO10), `RFID_SDA` (GPIO47). 
4. Route these specific CS labels to their respective header. 
5. Connect `+3.3V` (or 5V if the specific TFT module requires it) and `GND` to all headers.

---

## **Module 7: The Sensors**
Direct integration of the weight scale and temperature chips onto the PCB.

### **Components Needed**
*   **1x Amp IC:** `HX711` by Avia Semiconductor (Package: SOP-16) - **[LCSC: C14312]**
*   **1x Temp IC:** `SHT40-AD1B` by Sensirion (Package: DFN-4) - **[LCSC: C2841663]**
*   **2x Pull-up Resistors:** `4.7kΩ` (Size: 0603) - **[LCSC: C23162]**
*   **2x Decoupling Caps:** `100nF` (Size: 0603) - **[LCSC: C14663]**
*   **1x Header:** `JST-XH 4-Pin` (2.54mm pitch) - **[LCSC: C144393]**

### **Wiring Steps**
1. **HX711:** 
    * Connect `AVDD` and `VCC` to `+3.3V` (Add a **100nF cap** to GND nearby). 
    * Connect `SCK` to ESP32 **GPIO5**. Connect `DOUT` to ESP32 **GPIO6**. 
    * Connect the E+/E- and A+/A- pins directly to the 4-pin header for your load cell bar.
2. **SHT40:** 
    * Connect `VDD` to `+3.3V` (Add a **100nF cap** to GND nearby). 
    * Connect `SDA` to ESP32 **GPIO2**, and `SCL` to your chosen clock pin (e.g., GPIO1). 
3. **Critical I2C Step:** Add a **4.7kΩ pull-up resistor** from `SDA` to `+3.3V`, and another **4.7kΩ pull-up resistor** from `SCL` to `+3.3V`.

---

### **Done!**
Once every module above is drawn in your KiCad schematic, run the **Design Rules Check (DRC)**. When it returns zero errors, you are ready to assign footprints and begin routing the physical PCB!
