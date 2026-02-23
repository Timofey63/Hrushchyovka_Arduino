#include <Arduino.h>
#include <roomManager.h>

RoomManager rm;//16 rooms

void setup() 
{
  Serial.begin(9600);
  rm.begin(2,3,4);
  Serial.print("init");

  rm._rooms[7]->setEntrance();
}

void loop() 
{
  rm.update();
}
