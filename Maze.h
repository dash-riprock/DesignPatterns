// Maze.h
// Represents a collection of rooms.
// Can find a particular room given room number.
#ifndef maze_h
#define maze_h

#include "CommonDefs.h"
#include "MapSite.h"
#include "Room.h"

class Maze {
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;
private:
    //
};
#endif
