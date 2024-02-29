/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sia                                                       */
/*    Created:      2/7/2024, 10:29:18 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "../include/vex.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller(primary);

// Set up motors and controls
motor Left(PORT10, ratio18_1);
motor Right(PORT1, ratio18_1, true);
drivetrain DT(Left, Right, 320, 230, 130, mm, 1);

// Instantiate ultrasonic sensor
triport TriportArray(PORT22);
// analog_in Sense(TriportArray.G);
sonar Sonar(TriportArray.G);

void pre_auton(void) {
  Brain.Screen.print("Pre-autonomous functions...");
  DT.setTurnVelocity(20, rpm);
  DT.setDriveVelocity(50, rpm);
  Sonar.setMaximum(130, mm);

  return;
}

void Forward(void) { DT.driveFor(500, mm, true); }

void TurnRight(void) { DT.turnFor(right, 65, deg, true); }

void TurnLeft(void) { DT.turnFor(left, 65, deg, true); }

void TurnAround(void) { DT.turnFor(right, 180, deg, true); }

int absoluteOrientation = 0;
/**
 *	90
 *180		0
 *	270
 */

void TurnEast(void) {
	if (absoluteOrientation < 180) {
		DT.turnFor(right, absoluteOrientation, deg, true);
		absoluteOrientation = 0;
	}

	if (absoluteOrientation > 180) {
		DT.turnFor(left, absoluteOrientation-180, deg, true);
		absoluteOrientation = 0;
	}
}


void autonomous(void) {
  Brain.Screen.clearLine();
  Brain.Screen.print("Autonomous functions...");
  Brain.Screen.print(Sonar.foundObject());
  // Brain.Screen.print(Sonar.distance(mm));

	Forward();
	TurnRight();
	TurnRight();
	Forward();

}

void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}

int main() {
  // Competition-specific callbacks
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();
  Brain.Screen.clearLine();
  Brain.Screen.print("Waiting for input...");

  // while (!Sonar.foundObject()) {
  //   wait(100, msec);
  // }
  // Sonar.changed(autonomous);
  // Controller.ButtonA.released(autonomous);

  autonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
