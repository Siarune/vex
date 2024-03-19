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
distance Distance(PORT11);

// Set up motors and controls
motor Left(PORT10, ratio18_1);
motor Right(PORT1, ratio18_1, true);
drivetrain DT(Left, Right, 320, 230, 130, mm, 1);

// Pre-path setup
void pre_auton(void) {
  Brain.Screen.print("Pre-autonomous functions...");
  DT.setTurnVelocity(20, rpm);
  DT.setDriveVelocity(30, rpm);
  this_thread::sleep_for(1000);

  return;
}

// Directional controls
void Forward(void) { DT.driveFor(500, mm, true); }
void Backward(void) { DT.driveFor(-500, mm, true); }
void TurnRight(void) { DT.turnFor(right, 67, deg, true); }
void TurnLeft(void) { DT.turnFor(left, 67, deg, true); }
void TurnAround(void) { DT.turnFor(right, 180, deg, true); }
void MoveRight(void) { 
  TurnRight();
  Forward();
}
void MoveLeft(void) {
  TurnLeft();
  Forward();
}

// Pathfinding function
void autonomous(void) {
  Brain.Screen.clearLine();
  Brain.Screen.print("Autonomous functions...");


}

void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}


int main() {
  pre_auton();
  Brain.Screen.clearLine();
  Brain.Screen.print("Waiting for input...");
  // Controller.ButtonA.released(autonomous);

  while (Distance.objectDistance(mm) > 10) {
    this_thread::sleep_for(10);
  }
  autonomous();


  // Prevent main from exiting with an infinite loop.
  while (1) {
    this_thread::sleep_for(10);
    }
}
