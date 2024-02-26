/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sia                                                       */
/*    Created:      2/7/2024, 10:29:18 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller(primary);

// Set up motors and controls
motor Left(PORT10, ratio18_1);
motor Right(PORT1, ratio18_1, true);
// motor_group Motors = motor_group(Left, Right);
drivetrain DT(Left, Right);

// Instantiate ultrasonic sensor
triport TriportArray(PORT22);
sonar Sonar(TriportArray.G);


void pre_auton(void) {
  Brain.Screen.print("Pre-autonomous functions...");
  // DT.setGearRatio(1/18);
  DT.setTurnVelocity(20, rpm);  
  DT.setDriveVelocity(10, rpm);

  return;
}


void autonomous(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("Autonomous functions...");

  // DT.turnFor(right, 90, deg, true);
  DT.drive(forward, 50, rpm);
  // DT.turn(right);
  
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
  Brain.Screen.print("Waiting for input...");
  Controller.ButtonA.released(autonomous);  
  // Sonar.changed(autonomous);
  // autonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
