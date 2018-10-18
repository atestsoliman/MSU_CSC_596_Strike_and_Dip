//////////////////////////////////////////////////////////////////
//Modified by Ho Yun Bobby Chan @ SparkFun Electronics Inc.
//January 26, 2016
//©2011 bildr
//http://bildr.org/2011/06/easydriver/
//Released under the MIT License - Please reuse change and share
//
//Description: Using the example code from Bildr to test the
//speed of the small stepper motor [https://www.sparkfun.com/products/10551].
//Timing it with a watch, speed looked to be about 997-999 revolutions
//per minute (RPM) using a 12V benchtop power supply.
//Using the easy stepper with your arduino
//use rotate and/or rotateDeg to controll stepper motor
//speed is any number from .01 -> 1 with 1 being fastest - 
//Slower Speed == Stronger movement

/////////////////////////////////////////////////////////////////

#define DIR_PIN 2
#define STEP_PIN 3
int counter = 0; //counter to determine the amount of revolutions

void setup() { 
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT); 
  Serial.begin(9600);
} 

void loop(){ 

  //rotate a specific number of microsteps (8 microsteps per step)
  //a 48 step stepper would take 384 micro steps for one full revolution
  rotate(384, 1);//calculated from step angle of 7.5 degrees (360/7.5 = 48) at full speed
  counter++; 
  Serial.print("Counter = "); //display revolutions on the serial monitor
  Serial.println(counter); 
}

void rotate(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN,dir); 

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(usDelay); 
  } 
} 

void rotateDeg(float deg, float speed){ 
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0)? HIGH:LOW;
  digitalWrite(DIR_PIN,dir); 

  int steps = abs(deg)*(1/0.225);
  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(usDelay); 
  } 
}
