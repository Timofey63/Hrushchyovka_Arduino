#pragma once
#include <Arduino.h>

enum RoomMode
{
    FLAT,   
    ENTRANCE
};

class Room
{
private:
public:
    
    RoomMode mode;
    bool isActive;
    unsigned position;
    Room(int pos);
    void on();
    void off();
    void update();

    unsigned timeGlow;
    unsigned long lastGlow;

    void setEntrance();
};