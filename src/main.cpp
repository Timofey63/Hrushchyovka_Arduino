#include <Arduino.h>
#include <roomManager.h>

RoomManager rm;//16 rooms

void setup() 
{
  Serial.begin(9600);
  rm.begin(2,3,4);
  Serial.print("init");
}

void loop() 
{
  rm.update();
}
