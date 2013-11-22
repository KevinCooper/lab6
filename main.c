#include <msp430.h> 
#include "robotLibrary/robotLibrary.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initRobot();
    turnRightWheel();
    //moveForward(50,50);
        while (1) {
        		//moveForward(80,30);
      //  		turnLeftWheel();
        		//turnRightWheel();
            }
	return 0;
}

