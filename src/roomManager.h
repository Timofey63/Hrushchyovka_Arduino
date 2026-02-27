#pragma once
#include <Arduino.h>
#include <room.h>

class RoomManager
{
private:
    unsigned _countFloor;
    unsigned _countRooms;

    int _dataPin, _clockPin, _latchPin;
    byte* _floor;
    Room** _rooms;
public:
    RoomManager(int countFloor);
    void begin(int dataPin, int clockPin, int latchPin);
    void addRoom(Room* room);
    void update();
    void updateLight();
    void setEntrance(int index, int time);
    void setIntensity(int index, int time);

    void setRandTime(unsigned, unsigned);
};


