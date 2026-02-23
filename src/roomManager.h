#pragma once
#include <Arduino.h>
#include <room.h>

class RoomManager
{
private:
    static const int COUNT_FLOOR = 2;
    static const unsigned COUNT_ROOMS = COUNT_FLOOR * 8;

    int _dataPin, _clockPin, _latchPin;
    byte _floor[COUNT_FLOOR];
public:
    Room* _rooms[COUNT_ROOMS];
    RoomManager();
    void begin(int dataPin, int clockPin, int latchPin);
    void addRoom(Room* room);
    void update();
    void updateLight();
};


