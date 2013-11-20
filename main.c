#include <msp430.h> 
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

void setupClock(){
    TACTL &= ~MC1|MC0;            // stop timer A0
    TACTL |= TACLR;                // clear timer A0
    TACTL |= TASSEL1;           // configure for SMCLK
    TACCR0 = 200;                // set signal period to 200 clock cycles (~100 microseconds)
    TACCR1 = 10;                // set duty cycle to 50/200 (25%)
    TACCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
    TACTL |= MC0;                // count up
}

void turnLeft(){
	//Undo any left wheel movement
    P1DIR &= ~BIT2;                // TA0CCR1 on P1.2
    P1SEL &= ~BIT2;
    //Set up right turn movement
	P2DIR |= BIT1;					//Set up P2.1
	P2SEL |= BIT1;					//Set up P2.1

}
void turnRight(){
	//Undo any right wheel movement
	P2DIR &= ~BIT1;					//Set up P2.1
	P2SEL &= ~BIT1;
	//Set up left turn movement
    P1DIR |= BIT2;                // TA0CCR1 on P1.2
    P1SEL |= BIT2;
}

void moveForward(){

}
