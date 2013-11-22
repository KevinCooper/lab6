/*
 * robotLibrary.h
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Kevin.Cooper
 */

#ifndef ROBOTLIBRARY_H_
#define ROBOTLIBRARY_H_

#include <msp430.h>



void initRobot();
void turnLeftWheel();
void turnRightWheel();
void turnLeftWheelBack();
void turnRightWheelBack();
void stopRight();
void stopLeft();
void modTimer(int speedLeft, int speedRight);
void moveForward(int tuneLeft, int tuneRight);
void moveBackward(int tuneLeft, int tuneRight);
void leftTurn();
void rightTurn();
void halfRight();
void halfLeft();
void stop();


#endif /* ROBOTLIBRARY_H_ */
