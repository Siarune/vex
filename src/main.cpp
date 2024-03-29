/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sia (Aidan Sharp)                                         */
/*    Created:      2/7/2024, 10:29:18 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// Instantiate coms
brain Brain;
controller Controller(primary);
distance Distance(PORT20);

// Set up motors and controls
motor Left(PORT11, ratio18_1);
motor Right(PORT12, ratio18_1, true);
drivetrain DT(Left, Right, 320, 230, 130, mm, 1);

// Pre-path setup
void pre_auton(void) {
  Brain.Screen.print("Pre-autonomous setup...");

  DT.setTurnVelocity(30, rpm);
  DT.setDriveVelocity(30, rpm);

  this_thread::sleep_for(500);
  return;
}

void Enter(void) { DT.driveFor(400, mm, true); }
void Forward(int t = 1) { DT.driveFor(t * 500, mm, true); }
void Backward(int t = 1) { DT.driveFor(t * -500, mm, true); }
void TurnRight(int t = 1) { DT.turnFor(t * 78, deg, true); }
void TurnLeft(int t = 1) { DT.turnFor(t * -78, deg, true); }

void autonomous(void) {
  Brain.Screen.clearLine();
  Brain.Screen.print("Autonomous functions...");
}

int main() {
  pre_auton();
  Brain.Screen.clearLine();
  Brain.Screen.print("Waiting for input...");

  // Controller.ButtonA.released(autonomous);
  while (Distance.objectDistance(mm) > 20) {
    this_thread::sleep_for(10);
  }
  //   autonomous();

  // Prevent main from exiting with an infinite loop.
  while (1) {
    this_thread::sleep_for(10);
  }
}
