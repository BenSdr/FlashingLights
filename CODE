#include <msp430.h>
#define RED_LED BIT0 // P1.0
#define GREEN_LED BIT6 // P6.6
#define BUTTON1 BIT1 // push button P4.1
#define BUTTON2 BIT3 // push button P2.3

void main(void)
{
    // Stop the watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    // Initialize LEDs
    P1OUT &= ~RED_LED;  // Ensure red LED is off
    P6OUT &= ~GREEN_LED; // Ensure green LED is off
    P1DIR |= RED_LED;   // Set P1.0 as output (red LED)
    P6DIR |= GREEN_LED; // Set P6.6 as output (green LED)

    // Initialize BUTTON1
    P4DIR &= ~BUTTON1; // Set P4.1 as input (BUTTON1)
    P4REN |= BUTTON1; // Enable pull-up/down resistor on P4.1
    P4OUT |= BUTTON1; // Set P4.1 to use pull-up resistor

    // Initialize BUTTON2
    P2DIR &= ~BUTTON2; // Set P2.3 as input (BUTTON2)
    P2REN |= BUTTON2; // Enable pull-up/down resistor on P2.3
    P2OUT |= BUTTON2; // Set P2.3 to use pull-up resistor

    // Disable high-impedance mode to activate GPIO settings
    PM5CTL0 &= ~LOCKLPM5;

    while(1) {
        // Handle BUTTON1 press
        if ((P4IN & BUTTON1) == 0x00) { // Check if BUTTON1 is pressed
            _delay_cycles(5000); // Debounce delay
            if ((P4IN & BUTTON1) == 0x00) { // Confirm BUTTON1 is still pressed
                P1OUT ^= RED_LED; // Toggle the red LED
            }
            // Wait for BUTTON1 to be released
            while ((P4IN & BUTTON1) == 0x00);
        }

        // Handle BUTTON2 press
        else if ((P2IN & BUTTON2) == 0x00) { // Check if BUTTON2 is pressed
            _delay_cycles(5000); // Debounce delay
            if ((P2IN & BUTTON2) == 0x00) { // Confirm BUTTON2 is still pressed
                P6OUT ^= GREEN_LED; // Toggle the green LED
            }
            // Wait for BUTTON2 to be released
            while ((P2IN & BUTTON2) == 0x00);
        }
    }
}
