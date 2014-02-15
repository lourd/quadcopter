/*
QuadCopter firmware
This is the main loop
*/

#include "Config.h" //Config holds all PID parameters and more
#include <SPI.h> //need SPI to communicate with IMU
#include <PIDCont.h> //This is the PID library
#include <avr/pgmspace.h>

PIDCont PIDroll,PIDpitch,PIDyaw; //This creates the 3 PID controllers using the PID library

unsigned long tp;  //This is going to be the present time in milliseconds

int desRoll = 0; //Desired Roll
int desPitch = 0; //Desired Pitch
int desYaw = 0; //Desired Yaw

int actualRoll; //actual Roll
int actualPitch; //actual Pitch
int actualYaw; //actual Yaw

int throttle=MOTOR_ZERO_LEVEL;  //this is the nominal motor value

void setup() {
  motorInit(); //initialize the motor pins
  BluetoothInit(); //initialize the bluetooth reciever
  motorMove(); //Make the motors start spinning at nominal level
  PID_init(); //set all PID paraameters
  tp=millis(); //present time in milliseconds - used for the PID control, and also to read sensor values
}

void loop() {
  updateSensorVal();
  FlightControl();
}
