#pragma once
#include <Arduino.h>

class Room
{
private:
public:
    bool isActive;
    unsigned position;
    Room(int pos);
    void on();
    void off();
    void update();

    unsigned timeGlow;
    unsigned long lastGlow;
};