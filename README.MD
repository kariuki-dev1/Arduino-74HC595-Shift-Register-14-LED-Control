# Arduino 74HC595 Shift Register – 14 LED Control

## 📌 Project Overview

This project demonstrates how to control **16 LEDs using an Arduino Uno and two 74HC595 shift registers**.

Instead of connecting each LED directly to an Arduino pin, the 74HC595 shift registers expand the number of digital outputs available. The two registers are connected in series (daisy-chained), allowing the Arduino to control all 16 LEDs using only three signal pins.

The project is simulated in [Wokwi](https://wokwi.com/).

## 🎯 Objectives

- Understand how shift registers work.
- Learn how to use Arduino's `shiftOut()` function.
- Understand serial data transfer using a clock signal.
- Learn how to daisy-chain multiple 74HC595 shift registers.
- Control 16 LEDs using fewer Arduino pins.

## 🧰 Components Used

- Arduino Uno
- 2 × 74HC595 shift registers
- 16 × LEDs
- 16 × 1 kΩ resistors
- Breadboard
- Jumper wires
- Wokwi simulator

## 🔌 Pin Connections

### Arduino Uno to the first 74HC595

| Arduino pin | 74HC595 pin   | Function                       |
| ----------- | ------------- | ------------------------------ |
| D2          | DS (pin 14)   | Serial data input              |
| D5          | SHCP (pin 11) | Shift register clock           |
| D4          | STCP (pin 12) | Storage register clock / latch |
| 5V          | VCC (pin 16)  | Power                          |
| GND         | GND (pin 8)   | Ground                         |
| 5V          | MR (pin 10)   | Prevents clearing the register |
| GND         | OE (pin 13)   | Enables outputs                |

### Connecting the second 74HC595

- Connect the first register's `Q7S` serial output to the second register's `DS` input.
- Connect both registers' `SHCP` pins together.
- Connect both registers' `STCP` pins together.
- Connect both registers' `MR` pins to 5V and `OE` pins to GND.
- Power both registers from 5V and GND.

Each LED should have its own current-limiting resistor.

## 💻 How It Works

The Arduino uses `shiftOut()` to transmit data one bit at a time.

The process has three main steps:

1. Set the latch pin LOW to prepare for updating the outputs.
2. Use `shiftOut()` to transmit the LED pattern to the shift registers.
3. Set the latch pin HIGH to update the outputs with the transmitted pattern.

Two calls to `shiftOut()` transmit two bytes, giving the two registers 16 bits of LED control data.

For example:

- `0b11111111` represents eight HIGH bits.
- `0b`111111111represents eight LOW bits.

The clock signal synchronizes the transfer of individual bits, while the latch signal updates the outputs after the data has been transmitted.

## 🧠 Key Concepts Learned

- Serial data transmission
- Binary numbers and bytes
- `shiftOut()`
- Clock signals and rising edges
- Latch operation
- Digital outputs
- Daisy-chaining shift registers
- Expanding microcontroller output capacity

## 🚀 Possible Improvements

- Create a running LED pattern.
- Display binary counting from 0 to 255.
- Control all 16 LEDs using a `uint16_t` variable.
- Add pushbuttons to change LED patterns.
- Build a simple LED animation system.

## 📚 Learning Resources

- [Arduino ](https://docs.arduino.cc/language-reference/en/functions/advanced-io/shiftOut/)[`shiftOut()`](https://docs.arduino.cc/language-reference/en/functions/advanced-io/shiftOut/)[ reference](https://docs.arduino.cc/language-reference/en/functions/advanced-io/shiftOut/)
- [74HC595 shift register](https://www.ti.com/product/SN74HC595)
- [Wokwi Arduino Simulator](https://wokwi.com/)

## 👨‍💻 Author

Christopher Kariuki

*Learning IoT and Embedded Systems through practical projects.*
