
---

# Traffic Light with Counter

This project implements a **traffic light system with a countdown timer** using an **ATmega32 microcontroller**. The system allows normal traffic operation, adjustable red and green light durations, a police mode, and an off mode. 

## 🚦 Features

- **Normal Mode**: The traffic lights operate in a standard cycle (**Red → Green → Yellow**) while displaying the remaining time on a **7-segment display**.
- **Adjustable Red Light Duration**: Users can modify the **red light duration** and see real-time updates on the **7-segment display**.
- **Adjustable Green Light Duration**: Users can modify the **green light duration** similarly.
- **Police Mode**: The **red light blinks**, and `"PO"` is displayed on the **7-segment display**.
- **Off Mode**: Turns off all lights and the **7-segment display**.

---

![ezgif-4285d246e41e0c](https://github.com/user-attachments/assets/3a3a4ce5-0db2-4413-8372-6b5b0b784bf0)

> Graphical Guide for Operating the Circuit


## 🛠️ Hardware Components

- **ATmega32** microcontroller
- **7-segment display (2 digits)**
- **Push buttons** (for mode selection and time adjustment)
- **LEDs (Red, Yellow, Green)**

---

## 🔧 Circuit Connections

| Component | ATmega32 Pin |
|-----------|-------------|
| **Green LED** | `PA0` |
| **Yellow LED** | `PA1` |
| **Red LED** | `PA2` |
| **7-Segment (Left - Tens Place)** | `PORTD (PD0 - PD6)` |
| **7-Segment (Right - Ones Place)** | `PORTC (PC0 - PC6)` |
| **Normal Mode Button** | `PB0` |
| **Set Red Time Button** | `PB1` |
| **Set Green Time Button** | `PB2` |
| **Police Mode Button** | `PB3` |
| **Off Button** | `PB4` |
| **Increase Time (`Time+`)** | `PB5` |
| **Decrease Time (`Time-`)** | `PB6` |

---

## 🎮 How to Use

### **1️⃣ Normal Mode**
Press the **Normal** button (`PB0`). The **traffic lights cycle normally**:  
🔴 **Red → 🟢 Green → 🟡 Yellow**  
The **remaining time** for each light is displayed on the **7-segment display**.

---

### **2️⃣ Adjusting Red Light Duration**
1. Press **Set Red** (`PB1`) to enter red time adjustment mode.  
   - The **red LED** turns on, and the **current red light duration** is shown on the **7-segment display**.
2. Use **Time+ (`PB5`)** to **increase** the red light duration.  
3. Use **Time- (`PB6`)** to **decrease** the red light duration.  
4. To **save changes**, press any other mode button (e.g., **Normal, Police, or Set Green**).

---

### **3️⃣ Adjusting Green Light Duration**
1. Press **Set Green** (`PB2`) to enter green time adjustment mode.  
   - The **green LED** turns on, and the **current green light duration** is shown on the **7-segment display**.
2. Use **Time+ (`PB5`)** to **increase** the green light duration.  
3. Use **Time- (`PB6`)** to **decrease** the green light duration.  
4. To **save changes**, press any other mode button (e.g., **Normal, Police, or Set Red**).

---

### **4️⃣ Police Mode**
Press the **Police** button (`PB3`).  
- The **red LED blinks continuously**.  
- `"PO"` is displayed on the **7-segment display**.

---

### **5️⃣ Off Mode**
Press the **Off** button (`PB4`).  
- **All LEDs and the 7-segment display turn off.**

---

## 🚀 Getting Started

### **1️⃣ Clone the Repository**
```bash
git clone https://github.com/RezaGooner/Traffic-Light-with-Counter.git
cd Traffic-Light-with-Counter
```

### **2️⃣ Compile & Upload the Code**
Use **Atmel Studio**, **AVR-GCC**, or **Arduino IDE** (if adapted for ATmega) to compile and upload the firmware.

### **3️⃣ Simulate in Proteus**
- Open the provided **Proteus** simulation file.
- Run the simulation and test different modes.

---
