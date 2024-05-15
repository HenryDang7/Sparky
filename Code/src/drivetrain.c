/*
	This file contains all of the definitions declared in the "drivetrain.h" header file
	Contributions: Henry Dang
*/

// Include Headers
#include "drivetrain.h"

// Define Variables
double currentSpeeds[] = {0, 0, 0, 0}; /* The index of the elements correspond to: TopLeft, TopRight, BottomLeft, BottomRight */
double sinA, cosA, maxA;

void updateHeading(double throttle, double angle, double turn) {
	// Translates the directions into something relative to the vectors
	angle += M_PI / 4;
	sinA = sin(angle);
	cosA = cos(angle);

	// Scales up the inputs if a limit is met
	maxA = abs(sinA) > abs(cosA) ? abs(sinA) : abs(cosA);
	sinA /= maxA;
	cosA /= maxA;

	// Sets the desired speeds
	currentSpeeds[0] = throttle * cosA + turn;
	currentSpeeds[1] = throttle * sinA - turn;
	currentSpeeds[2] = throttle * sinA + turn;
	currentSpeeds[3] = throttle * cosA - turn;

	// Scales down the motor speeds if one is capped
	if (throttle + abs(turn) > 1) {
		for (int i = 0; i < 4; i++) {
			currentSpeeds[i] /= throttle + turn;
		}
	}

	updateDriveMotors(currentSpeeds);
}

/* Updates the motor speeds given an array of speeds */
void updateDriveMotors(double speeds[]) {
	motorSet(TOP_LEFT_MOTOR_PORT, speeds[0]);
	motorSet(TOP_RIGHT_MOTOR_PORT, speeds[1]);
	motorSet(BOTTOM_LEFT_MOTOR_PORT, speeds[2]);
	motorSet(BOTTOM_RIGHT_MOTOR_PORT, speeds[3]);
}