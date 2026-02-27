#include <roomManager.h>

RoomManager::RoomManager(int countFloor)
{
    _countFloor = countFloor;
    _countRooms = _countFloor * 8;
    
    _rooms = new Room*[_countRooms];
    _floor = new byte[_countFloor];

    for (unsigned i = 0; i < _countRooms; i++)
    {
        _rooms[i] = nullptr;
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

    for(unsigned i = 0; i < _countRooms; i++)
    {
        addRoom(new Room(i));
    }

    setRandTime(1000, 3000);
}

void RoomManager::addRoom(Room* room)
{
    if (room->position < 0 || room->position >= _countRooms) return;
    _rooms[room->position] = room;
}


void RoomManager::update()
{
    bool needUpdate = false;
    for(unsigned i = 0; i < _countRooms; i++)
    {
        if (_rooms[i] == nullptr) continue;

        Room* room = _rooms[i];
        room->update();
        int floorIndex = i / 8;
        byte currentFloor = _floor[floorIndex];
        int bitPosition = i % 8;

        
        if(room->getActive())
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
    for (unsigned i = 0; i < _countFloor; i++) 
    {
        shiftOut(_dataPin, _clockPin, LSBFIRST, _floor[i]);
    }
    digitalWrite(_latchPin, HIGH);
}

void RoomManager::setEntrance(int index, int time)
{
    _rooms[index]->setRoomMode(time, ENTRANCE);
}

void RoomManager::setIntensity(int index, int time)
{
    _rooms[index]->setRoomMode(time, BLINK);
}

void RoomManager::setRandTime(unsigned minTimeLight, unsigned maxTimeLight)
{
    for(unsigned i = 0; i < _countRooms; i++)
    {
        _rooms[i]->setRandTime(minTimeLight, maxTimeLight);
    }
}