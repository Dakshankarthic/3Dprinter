i n# Reddit PCB Review Post Template

If you want to get feedback from veteran engineers on Reddit, the best places to post are **r/PrintedCircuitBoard**, **r/KiCad**, or **r/esp32**. 

*(Note: r/PrintedCircuitBoard has strict rules. They require you to upload clear pictures of your schematic and your board traces to get approved!)*

## 📸 Images You MUST Export from KiCad to Attach:
1. **Schematic:** Export as a high-res PDF or clear PNG (`File -> Plot -> PDF`). If people can't read the component text, they won't review it.
2. **PCB 2D View:** A clear screenshot of your fully routed board in KiCad.
3. **PCB 3D View:** A screenshot of your beautiful 3D board layout.

---

## 📝 Copy & Paste the text below to create your post:

**Post Title:** [Review Request] First Custom PCB! ESP32-S3 3D Printer Controller Board (High Power + Analog Load Cell)

**Post Body:**
Hi everyone, 

This is my first major custom PCB project and I would love some feedback before I send it off to be manufactured (fabricating as a standard 4-layer JLC7628 stackup).

**Project Overview:**
I’m building a custom smart controller for a 3D printer. The board is powered by an ESP32-S3-WROOM-1 module. It’s responsible for managing logic, driving a high-amperage 12V heater and cooling fan via MOSFETs, and reading sensitive analog data from a filament spool load cell using an HX711.

**Key Design Features:**
* **Logic/Comms:** ESP32-S3, standard CP2102N USB-to-UART auto-reset bridge, BOOT/EN tactile buttons.
* **Power Supply:** 5V in via USB-C (for logic), regulated down to 3.3V via an AMS1117-3.3.
* **High Power Rail:** A separate 12V input specifically to drive the hotend heater cartridge and fans using AOD4184A MOSFETs.
* **Sensors:** Off-board green HX711 breakout module (to avoid soldering the bare IC/analog caps) connected via 4-pin header, and an external DHT22.
* **Placement Strategy:** High power 12V traces/MOSFETs are physically isolated on the left side of the board, while the delicate logic and sensors sit on the right side.
* **Routing:** Mostly routed using AI (Quilter) based on my constraints (0.2mm clearance/track minimums, 5A width calculations for the 12V switching net). 

**My Specific Questions for the Community:**
1. **Physical Layout:** I tried my best to isolate the 12V heavy-load section on the left from the logic on the right. Does this separation look sufficient to prevent electrical noise from messing with the ESP32?
2. **ESP32 Placement:** I've pushed the ESP32 module to the top edge so the antenna trace area completely overhangs the board. Does this placement and clearance look correct for good Wi-Fi signal?
3. **General Best Practices:** Is there anything glaringly wrong that I missed? (e.g., decoupling caps placed poorly, missing pull-ups, trace widths on the MOSFETs not looking beefy enough).

I’ve attached the full schematic, the 3D render, and the 2D layout. Any brutal or constructive criticism is incredibly appreciated—I want to learn! Thank you!
