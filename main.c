#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"

/*
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initRobot();
	//turnLeftWheelBack();
	//moveBackward(40, 40);
	while (1) {
		leftTurn();
		__delay_cycles(1000000);
		rightTurn();
		__delay_cycles(1000000);
		halfLeft();
		__delay_cycles(1000000);
		halfRight();
		__delay_cycles(1000000);
	}
	return 0;
}

