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
		moveForward(50, 50);
		__delay_cycles(500000);
		stop();
		__delay_cycles(1000000);
		moveBackward(50, 50);
		__delay_cycles(500000);
		stop();
		__delay_cycles(2000000);
		halfLeft();
		__delay_cycles(500000);
		stop();
		__delay_cycles(1000000);
		halfRight();
		__delay_cycles(500000);
		stop();
		__delay_cycles(1000000);
		leftTurn();
		__delay_cycles(500000);
		stop();
		__delay_cycles(1000000);
		rightTurn();
		__delay_cycles(500000);
		stop();
		__delay_cycles(1000000);
	}
	return 0;
}

