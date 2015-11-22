#ifndef ROOM_H
#define ROOM_H

#include "../include/Player.h"
//#include "../include/Item.h"
//#include "../include/Monster.h"

typedef struct _Room{
	int x;
	int y;
	int width;
	int height;

} Room;

//Room Functions
Room* createRoom(int x, int y, int width, int height);
int deleteRoom(Room* room);
Room** generateRooms(int numRooms, int levelWidth, int levelHeight);
int checkForSpace(int x, int y, int width, int height, Room** rooms, int numRooms);
Player* spawnPlayer(Room** rooms, int numRooms);


#endif 