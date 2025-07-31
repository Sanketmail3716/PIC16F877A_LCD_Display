# PIC16F877A LCD Display Interface (4-bit Mode)

This project demonstrates how to interface a 16x2 LCD with the PIC16F877A microcontroller using the 4-bit mode. The code initializes the LCD and displays custom text ("PALLAVI" and "BAHULEKAR") on the LCD screen.

---

## 🧠 Features

- Uses **PIC16F877A** microcontroller.
- Interfaced with **16x2 LCD** in 4-bit mode.
- Displays two lines of text.
- Written in **Embedded C** using **MPLAB X IDE** and **XC8 Compiler**.
- Based on **20 MHz crystal oscillator**.

---

## 🛠️ Hardware Requirements

- PIC16F877A microcontroller  
- 16x2 LCD display  
- 20 MHz crystal oscillator  
- Capacitors (typically 22pF for crystal)  
- Potentiometer (for LCD contrast)  
- Breadboard and jumper wires  
- Power supply (5V regulated)

---

## 📦 Connections

| LCD Pin | Connected To |
|---------|--------------|
| RS      | RC0          |
| EN      | RC1          |
| D4      | RD4          |
| D5      | RD5          |
| D6      | RD6          |
| D7      | RD7          |
| VSS     | GND          |
| VDD     | +5V          |
| V0      | Potentiometer (contrast) |
| RW      | GND (Write mode) |

---

## 📂 Project Structure

PIC16F877A_LCD_Display/
├── main.c # Main source code
├── README.md # Project documentation


---

## 📋 How It Works

- Initializes LCD in 4-bit mode.
- Sends commands and data to the LCD.
- Displays:
  - "BAHULEKAR" on the first row
  - "PALLAVI" on the second row

---

## 🔧 Configuration Bits (in code)

```c
#pragma config FOSC = HS        // High-speed crystal
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = OFF      // Power-up Timer disabled
#pragma config BOREN = OFF      // Brown-out Reset disabled
#pragma config LVP = OFF        // Low-Voltage Programming disabled
#pragma config CPD = OFF        // Data EEPROM code protection disabled
#pragma config WRT = OFF        // Flash write protection disabled
#pragma config CP = OFF         // Flash code protection disabled

🧑‍💻 Author
Sanket Mali