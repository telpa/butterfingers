
/*
The two geared motors run pretty smooth set to 1/32 step @ 1000 steps/sec
For the non-geared motor, full step @ 1000 steps/sec (why???)
*/

#include "Arduino.h"
#include <AccelStepper.h>

//Create stepper objects. motor interface, stepPin, dirPin
// Motor interface = 1 (driver)
AccelStepper stepper1(1, 3, 2);
AccelStepper stepper2(1, 6, 5);
AccelStepper stepper3(1, 9, 8);

void setup(){

  // Set max speeds (steps per second) and accelerations
  stepper1.setMaxSpeed(4000);
  stepper2.setMaxSpeed(1000);
  stepper3.setMaxSpeed(1000);
  stepper1.setAcceleration(100);
  stepper2.setAcceleration(50);
  stepper3.setAcceleration(50);

  // Set positions to move to
  stepper1.moveTo(700);
  stepper2.moveTo(10000);
  stepper3.moveTo(10000);

  // Switch on motors
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);

}

void loop(){
  // Change direction at the limits for stepper 1
  if (stepper1.distanceToGo() == 0){
      stepper1.moveTo(-stepper1.currentPosition());
  }

  stepper1.run();
  stepper2.run();
  stepper3.run();
}
