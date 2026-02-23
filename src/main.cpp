#include <Arduino.h>
#include <roomManager.h>

RoomManager rm;

void setup() 
{
  Serial.begin(9600);
  
  rm.begin(2,3,4);

  for(int i = 0; i < 16; i++)
  {
    rm.addRoom(new Room(i));
  }

  Serial.print("init");
}

void loop() 
{
  rm.update();
}
