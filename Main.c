// main.c
#include <msp430.h>
#include "GPIO_Driver.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    gpioInitOut(1, BIT0); // Initialize P1.0 as output (RED_LED)
    gpioInitIn(4, BIT1); // Initialize P4.1 as input (BUTTON1)

    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default high-impedance mode

    unsigned char value = 0;
    while (1) {
        value = gpioInitStatus(4, BIT1);
        if (value == 0x00) {
            gpioWrite(1, BIT0, 1); // Turn on RED_LED
            __delay_cycles(50000);
            gpioWrite(1, BIT0, 0); // Turn off RED_LED
            __delay_cycles(50000);
        }
    }
}
