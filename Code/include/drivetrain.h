/*
	This file contains the declarations of the functions needed to operate Sparky's drivetrain
	Contributions: Henry Dang
*/

#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

// Include Headers
#include <API.h>
#include <math.h>

// Constants
#define TOP_LEFT_MOTOR_PORT 1
#define TOP_RIGHT_MOTOR_PORT 2
#define BOTTOM_LEFT_MOTOR_PORT 3
#define BOTTOM_RIGHT_MOTOR_PORT 4

// Functions
void updateHeading(double throttle, double angle, double turn);
void updateDriveMotors(double speeds[]);

#endif