/*
	This file contains the main loop that is running during the robot's operation
	Contributions: Henry Dang
*/

#include "main.h"

void operatorControl() {
	double desiredX, desiredY, desiredTurn;

	while (true) {
		desiredX = joystickGetAnalog(1, 4);
		desiredY = joystickGetAnalog(1, 3);
		desiredTurn = joystickGetAnalog(1, 1);
		
		updateHeading(atan2(desiredY, desiredX), sqrt(desiredX * desiredX + desiredY * desiredY), desiredTurn);
		delay(20);
	}
}