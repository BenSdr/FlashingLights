# FlashingLights
Basic MSP430 project for toggling LEDs using push buttons

MSP430 LED and Button Control

**Description**
This project demonstrates basic control of LEDs and push buttons using an MSP430 microcontroller. The code toggles a red LED when a button (BUTTON1) is pressed and toggles a green LED when another button (BUTTON2) is pressed. 

**Authors**
Ben Souder
Arturo Sanchez
Date Created: [9/4/24]
Last Updated: [9/11/24]

**Dependencies**
This project requires the following hardware and libraries:

MSP430 microcontroller
MSP430 header file (msp430.h), which is provided with the MSP430 software development kit (SDK).
No additional software libraries are required beyond the standard MSP430 toolchain.

**Code Overview**
The code configures two LEDs and two push buttons on the MSP430 microcontroller:

**LEDs:**

Red LED connected to pin P1.0
Green LED connected to pin P6.6

Buttons:

BUTTON1 connected to pin P4.1
BUTTON2 connected to pin P2.3

**Functionality**

BUTTON1:

Toggles the state of the red LED on P1.0.
A debounce delay is implemented to ensure stable button reading.

BUTTON2:

Toggles the state of the green LED on P6.6.
A debounce delay is also implemented for stable button handling.

**Contact**
For questions or issues, please contact:

Ben Souder: [besa28@lehigh.edu]
Arturo Sanchez: [ars528@lehigh.edu]


