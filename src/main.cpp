#include <Arduino.h>
#include <roomManager.h>

RoomManager rm(2);

void setup() 
{
  Serial.begin(9600);
  rm.begin(2,3,4);

  rm.setEntrance(7, 50);
  rm.setIntensity(8, 10);
}

void loop() 
{
  rm.update();
}
