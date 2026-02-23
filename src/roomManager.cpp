#include <roomManager.h>

RoomManager::RoomManager()
{
    for (unsigned i = 0; i < COUNT_ROOMS; i++)
    {
         _rooms[i] = nullptr;
    }
    
    for (unsigned i = 0; i < COUNT_FLOOR; i++)
    {
        _floor[i] = 0;
    }
}

void RoomManager::begin(int dataPin, int clockPin, int latchPin)
{
    _dataPin = dataPin;
    _clockPin = clockPin;
    _latchPin = latchPin;

    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);

    for(unsigned i = 0; i < COUNT_ROOMS; i++)
    {
        addRoom(new Room(i));
    }
}

void RoomManager::addRoom(Room* room)
{
    if (room->position < 0 || room->position >= COUNT_ROOMS) return;
    _rooms[room->position] = room;
}


void RoomManager::update()
{
    bool needUpdate = false;
    for(unsigned i = 0; i < COUNT_ROOMS; i++)
    {
        if (_rooms[i] == nullptr) continue;

        Room* room = _rooms[i];
        room->update();
        int floorIndex = i / 8;
        byte currentFloor = _floor[floorIndex];
        int bitPosition = i % 8;

        
        if(room->isActive)
        {
           if (!(currentFloor & (1 << bitPosition))) {
                _floor[floorIndex] = currentFloor | (1 << bitPosition);
                needUpdate = true;
            }
        }
        else
        {
            if (currentFloor & (1 << bitPosition)) {
                _floor[floorIndex] = currentFloor & ~(1 << bitPosition);
                needUpdate = true;
            }
        }
    }
    if (needUpdate) 
    {
        updateLight();
    }
}

void RoomManager::updateLight()
{
    digitalWrite(_latchPin, LOW);
    for (unsigned i = 0; i < COUNT_FLOOR; i++) 
    {
        shiftOut(_dataPin, _clockPin, LSBFIRST, _floor[i]);
    }
    digitalWrite(_latchPin, HIGH);
}