//  MapSite.h
#ifndef mapsite_h
#define mapsite_h

#include "CommonDefs.h"
 
//  Common abstract class for all components of Maze
class MapSite {
public:
    virtual void Enter() = 0;
};
#endif

// Room.h
#ifndef room_h
#define room_h

#include "CommonDefs.h"
#include "MapSite.h"

class Room : public MapSite {
public:
    Room(int roomNo);

    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

    virtual void Enter();

private:
    MapSite* _sides[4];
    int _roomNumber;
};
#endif

// Door.h
#ifndef door_h
#define door_h

#include "CommonDefs.h"
#include "MapSite.h"
#include "Room.h"

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void Enter();
    Room* OtherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};
#endif

// Wall.h
#ifndef wall_h
#define wall_h 

#include "CommonDefs.h"
#include "MapSite.h"

class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};
#endif

// Creates the maze.
#ifndef maze_game_h
#define maze_game_h

#include "CommonDefs.h"
#include "MapSite.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

class MazeGame {
public:
    Maze* CreateMaze();

private:
    //
};

Maze* MazeGame::CreateMaze() {
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);

    return aMaze;
}
#endif

