# Traffic Light Control System with Two-Digit Counter

This repository contains the C code and Proteus simulation files for a **Traffic Light Control System**. The system includes three LEDs (Red, Yellow, and Green) with different timing intervals, and a **two-digit 7-segment display** that shows the countdown for each light. The timing for each light can be adjusted using buttons, making the system interactive and customizable.

---

## Features
- **Three Traffic Lights**: Red, Yellow, and Green LEDs.
- **Two 7-Segment Display**: Displays the countdown timer for each light.
- **Adjustable Timings**: The duration for each light can be configured using buttons.
- **Proteus Simulation**: Fully simulated in Proteus for testing and visualization.
- **C Code**: Written in Embedded C using CodeVisionAVR.
- **Microcontroller**: Designed for the **ATmega32** microcontroller.

---

![bandicam 2025-03-07 02-40-58-368](https://github.com/user-attachments/assets/191d6322-5526-4059-bfc6-5e4605477a78)

---
## Simulation Instructions
To simulate the project, follow these steps:

1. **Open Proteus**:
   - Load the Proteus simulation file (`TrafficLight.pdsprj`) located in the `Proteus_Simulation` folder.

2. **Program the Microcontroller**:
   - Compile the C code located in the `CodeVision_C_Code` folder using **CodeVisionAVR**.
   - The generated HEX file is located in the `Debug` folder.
   - Program the HEX file onto the **ATmega32** microcontroller in the Proteus simulation.

3. **Run the Simulation**:
   - Start the simulation in Proteus.
   - Observe the traffic lights and the countdown on the 7-segment display.
   - Use the buttons to adjust the timing for each light.

---


## How It Works
1. **Traffic Light Cycle**:
   - The system cycles through the Red, Yellow, and Green lights.
   - Each light has a predefined countdown time, which is displayed on the 7-segment display.

2. **Adjustable Timings**:
   - Buttons are used to increase or decrease the duration of each light.
   - The updated timings are reflected in the countdown display.

3. **7-Segment Display**:
   - A two-digit 7-segment display shows the remaining time for the current light in a countdown format.

---

## Requirements
- **Software**:
  - Proteus (for simulation)
  - CodeVisionAVR (for compiling the C code)
- **Hardware** (for real-world implementation):
  - ATmega32 microcontroller
  - LEDs (Red, Yellow, Green)
  - Two 7-segment display
  - Buttons for adjusting timings

---

## Author
- **Reza Gooner**  
  GitHub: [RezaGooner](https://github.com/RezaGooner)
