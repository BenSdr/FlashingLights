// GPIO_Driver.c
#include <msp430.h>
#include "GPIO_Driver.h"

void gpioInitIn(unsigned int Port, unsigned char Pin) {
    switch (Port) {
        case 1: P1DIR &= ~Pin; P1REN |= Pin; P1OUT |= Pin; break;
        case 2: P2DIR &= ~Pin; P2REN |= Pin; P2OUT |= Pin; break;
        case 4: P4DIR &= ~Pin; P4REN |= Pin; P4OUT |= Pin; break;
        case 6: P6DIR &= ~Pin; P6REN |= Pin; P6OUT |= Pin; break;
    }
}

void gpioInitOut(unsigned int Port, unsigned char Pin) {
    switch (Port) {
        case 1: P1DIR |= Pin; P1OUT &= ~Pin; break;
        case 2: P2DIR |= Pin; P2OUT &= ~Pin; break;
        case 4: P4DIR |= Pin; P4OUT &= ~Pin; break;
        case 6: P6DIR |= Pin; P6OUT &= ~Pin; break;
    }
}

unsigned char gpioInitStatus(unsigned int Port, unsigned char Pin) {
    unsigned char value;
    switch (Port) {
        case 1: value = P1IN & Pin; break;
        case 2: value = P2IN & Pin; break;
        case 4: value = P4IN & Pin; break;
        case 6: value = P6IN & Pin; break;
    }
    return value;
}

void gpioWrite(unsigned int Port, unsigned char Pin, unsigned char value) {
    switch (Port) {
        case 1: if (value) P1OUT |= Pin; else P1OUT &= ~Pin; break;
        case 2: if (value) P2OUT |= Pin; else P2OUT &= ~Pin; break;
        case 4: if (value) P4OUT |= Pin; else P4OUT &= ~Pin; break;
        case 6: if (value) P6OUT |= Pin; else P6OUT &= ~Pin; break;
    }
}
