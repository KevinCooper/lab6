#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initRobot();
        while (1) {
        		moveForward(8,3);
            }
	return 0;
}

