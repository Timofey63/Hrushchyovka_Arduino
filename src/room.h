#pragma once
#include <Arduino.h>

enum RoomMode
{
    FLAT,   
    ENTRANCE,
    BLINK
};

class Room
{
private:
public:
    
    RoomMode _mode;
    bool isActive;
    unsigned position;
    Room(int pos);
    void on();
    void off();
    void update();

    unsigned timeGlow;
    unsigned long lastGlow;

    unsigned timeBlink;
    unsigned long lastBlink;

    void setRoomMode(int time, RoomMode mode);
};