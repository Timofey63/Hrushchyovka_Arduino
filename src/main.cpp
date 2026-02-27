#include <Arduino.h>
#include <roomManager.h>

RoomManager rm(2);

void setup() 
{
  Serial.begin(9600);
  rm.begin(2,3,4);
  rm.setRandTime(1000, 3000);

  //rm.setEntrance(7, 100);
  //rm.setIntensity(8, 100);
}

void loop() 
{
  rm.update();
}
