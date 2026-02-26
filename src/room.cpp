#include <room.h>
#include <Arduino.h>

Room::Room(int pos)
{
    position = pos;
    off();
    _mode = FLAT;
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
    
    if(_mode == FLAT)
    {
        if(currentTime - lastGlow >= timeGlow)
        {
            isActive = !isActive;
            lastGlow = currentTime;
        
            timeGlow = random(30000, 300000);
        }
    }
    if(_mode == ENTRANCE)
    {
        if (currentTime - lastGlow >= timeGlow)
        {
            isActive = !isActive;
            lastGlow = currentTime;
        }
    }

    if(_mode == BLINK)
    {
        if(currentTime - lastBlink >= timeBlink)
        {
            isActive = !isActive;
            lastBlink = currentTime;
        }

        // if(currentTime - lastGlow >= timeGlow)
        // {
        //     isActive = !isActive;
        //     lastGlow = currentTime;
        
        //     timeGlow = random(30000, 300000);
        // }
    }
    
}

void Room::setRoomMode(int time, RoomMode mode)
{
    _mode = mode;

    if(mode == ENTRANCE)
    {
        isActive = true;
        timeGlow = time;
    }
    if(mode == BLINK)
    {
        timeBlink = time;
    }
}