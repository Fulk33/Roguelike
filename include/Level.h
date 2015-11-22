#ifndef LEVEL_H
#define LEVEL_H
#include "../include/Room.h"


typedef struct _level {
	int width;
	int height;
	Room** rooms;
	int numRooms;
	Player* player;

	//Monster
	//Items
	//Platforms
} Level;

//Level functions
Level* createLevel(int width, int height, int numRooms);


#endif 