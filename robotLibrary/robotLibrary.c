/*
 * robotLibrary.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Kevin.Cooper
 */

#include <msp430.h>

void initRobot()
{
	TA0CTL &= ~(MC1 | MC0);            // stop timer A0
	TA0CTL |= TACLR;                // clear timer A0
	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA0CCR0 = 100;  // set signal period to 200 clock cycles (~100 microseconds)
	TA0CCR1 = 60;                // set duty cycle to 50/200 (10%)
	TA0CCTL0 |= OUTMOD_7;		// CCTL0 set/reset
	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA0CTL |= MC0;                // count up

	TA1CTL &= ~(MC1 | MC0);            // stop timer A1
	TA1CTL |= TACLR;                // clear timer A1
	TA1CTL |= TASSEL1;           // configure for SMCLK
	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 60;                // set duty cycle to 50/100 (10%)
	TA1CCTL0 |= OUTMOD_7;		//CCTL0 set/reset
	TA1CCTL1 |= OUTMOD_7;        // set TA1CCTL1 to Set / Reset mode
	TA1CTL |= MC0;                // count up
}

void turnLeftWheel()
{
	P1DIR |= BIT1;
	P1SEL |= BIT1;
	P1DIR |= BIT2;
	P1OUT &= ~BIT2;
}
void turnRightWheel()
{
	P2DIR |= BIT0;
	P2SEL |= BIT0;
	P2DIR |= BIT1;
	P2OUT &= ~BIT1;
}

void turnLeftWheelBack()
{
	P1DIR |= BIT2;
	P1SEL |= BIT2;
	P1DIR |= BIT1;
	P1OUT &= ~BIT1;
}
void turnRightWheelBack()
{
	P2DIR |= BIT1;
	P2SEL |= BIT1;
	P2DIR |= BIT0;
	P2OUT &= ~BIT0;
}

void stopRight()
{
	P2DIR &= ~(BIT1 | BIT0);
	P2SEL &= ~(BIT1 | BIT0);
	P2DIR |= (BIT0 | BIT1);
	P2OUT &= ~(BIT0 | BIT1);
}

void stopLeft()
{
	P1DIR &= ~(BIT2 | BIT1);
	P1SEL &= ~(BIT2 | BIT1);
	P1DIR |= (BIT1 | BIT2);
	P1OUT &= ~(BIT1 | BIT2);
}
void modTimer(int speedLeft, int speedRight)
{
	TA0CTL &= ~(MC1 | MC0);            // stop timer A0
	TA0CTL |= TACLR;                // clear timer A0
	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA0CCR0 = 100;  // set signal period to 200 clock cycles (~100 microseconds)
	TA0CCR1 = speedLeft;                // set duty cycle to 50/200 (10%)
	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Set / Reset mode
	TA0CCTL0 |= OUTMOD_7;		//CCTL0 set/reset
	TA0CTL |= MC0;                // count up

	TA1CTL &= ~(MC1 | MC0);            // stop timer A1
	TA1CTL |= TACLR;                // clear timer A1
	TA1CTL |= TASSEL1;           // configure for SMCLK
	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = speedRight;                // set duty cycle to 50/100 (10%)
	TA1CCTL0 |= OUTMOD_7;		//CCTL0 set/reset
	TA1CCTL1 |= OUTMOD_7;        // set TA1CCTL1 to Set / Reset mode
	TA1CTL |= MC0;                // count up
}
void moveForward(int tuneLeft, int tuneRight)
{
	modTimer(tuneLeft, tuneRight);
	turnRightWheel();
	turnLeftWheel();

}
void moveBackward(int tuneLeft, int tuneRight)
{
	modTimer(tuneLeft, tuneRight);
	turnLeftWheelBack();
	turnRightWheelBack();
}
void leftTurn()
{
	turnLeftWheel();
	__delay_cycles(350000);
	stopLeft();
}
void rightTurn()
{
	turnRightWheel();
	__delay_cycles(350000);
	stopRight();
}
void halfRight()
{
	turnRightWheel();
	__delay_cycles(150000);
	stopRight();
}
void halfLeft()
{
	turnLeftWheel();
	__delay_cycles(150000);
	stopLeft();
}
void stop()
{
	stopRight();
	stopLeft();
}
