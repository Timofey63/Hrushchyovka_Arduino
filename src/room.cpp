#include <room.h>
#include <Arduino.h>

Room::Room(int pos)
{
    position = pos;
    off();
    _mode = FLAT;
    lastGlow = 0;
    isActive = random(2) == 1;
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
        
            timeGlow = random(_minTimeLight, _maxTimeLight);
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
        if(currentTime - lastGlow >= timeGlow)
        {
            isActive = !isActive;
            lastGlow = currentTime;
            
            timeGlow = random(_minTimeLight, _maxTimeLight);
        }

        if(getActive() == true)
        {
            if(currentTime - lastBlink >= timeBlink)
            {
                baseActive = !baseActive;
                lastBlink = currentTime;
            
            }
        }
    }
}

void Room::setRandTime(unsigned minTimeLight, unsigned maxTimeLight)
{
    _minTimeLight = minTimeLight;
    _maxTimeLight = maxTimeLight;
}

bool Room::getActive()
{
    return isActive;
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