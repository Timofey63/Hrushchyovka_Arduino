#include <Arduino.h>
#include <roomManager.h>

RoomManager rm(5);

void setup() 
{
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  rm.begin(2,3,4);
  rm.setRandTime(10000, 30000);

  //rm.setEntrance(7, 100);
  //rm.setIntensity(8, 100);
}

void loop() 
{
  rm.update();
}