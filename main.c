#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"

void setupClock();
void turnLeft();
void turnRight();
void moveForward();
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    setupClock();
        while (1) {
        	turnLeft();
        	__delay_cycles(1000000);
        	turnRight();
        	__delay_cycles(1000000);
            }

	return 0;
}

