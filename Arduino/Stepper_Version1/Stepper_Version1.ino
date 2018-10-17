// Stepper Motor Bipolar
// Michael Knapp

// Include the Stepper library
#include <Stepper.h>

// Declare the used pins
int dirA = A0;
int dirB = A1;
int pwmA = A0;
int pwmB = A1;

// Declare a Stepper motor with 200 steps 
Stepper stepper1(200, dirA, dirB);

void setup() {
  // PWM pins require declaration when used as Digital
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  
  // Set PWM pins as always HIGH
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  
  // ToDo:  Set stepper motor speed I am not sure if this is a good speed or not?? 
  stepper1.setSpeed(60);
}
// main loop for each step you need to execute..
//1. I did 180 degees /
//2.in the positive then back 180 degrees 
//3. then neg 180 degrees 
void loop(){
  // Turn the stepper 100 steps which means 180 degrees
  stepper1.step(100);
  // Wait half second delay is in milsec.
  delay(500);
  
  // Turn the stepper 100 steps back which means -180 degrees
  stepper1.step(-100);
  // Wait half second
  delay(500);
  //Turn the stepper 100 steps back which means -180 degrees 
  stepper1.step(-100)
  //Wait half second 
  delay(500);
}
