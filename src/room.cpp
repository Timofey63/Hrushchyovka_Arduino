#include <room.h>
#include <Arduino.h>

Room::Room(int pos)
{
    position = pos;
    off();
    lastGlow = 0;
    timeGlow = random(1000, 3000);
}

void Room::on()
{
    isActive = true;
}

void Room::off()
{
    isActive = false;
}

void Room::update()
{
    unsigned long currentTime = millis();
    
    if(currentTime - lastGlow >= timeGlow)
    {
        isActive = !isActive;
        lastGlow = currentTime;
        
        timeGlow = random(30000, 300000);
    }
}