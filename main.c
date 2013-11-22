#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"

/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
	while (1) {
		turnRightWheel();
		turnLeftWheel();
		__delay_cycles(1000000);
		stopRight();
		stopLeft();
		__delay_cycles(1000000);
	}
	return 0;
}

