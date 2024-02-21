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

// Set up motors and controls
motor Left = motor(PORT10, ratio18_1);
motor Right = motor(PORT1, ratio18_1);
drivetrain DT = drivetrain(Left, Right);

controller Controller = controller(primary);

// Instantiate ultrasonic sensor
triport TriportArray(PORT22);
sonar Sonar = sonar(TriportArray.G);


void pre_auton(void) {
  // DT.setGearRatio(1/18);
  DT.setTurnVelocity(20, rpm);  
  DT.setDriveVelocity(10, rpm);

  return;
}


void autonomous(void) {

  // DT.turnFor(right, 90, deg, true);
  DT.drive(forward, 50, rpm);
  
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
  // Controller.ButtonA.released(autonomous);  
  // Sonar.changed(autonomous);
  autonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
