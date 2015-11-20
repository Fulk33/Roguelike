#ifndef LEVEL_H
#define LEVEL_H

#include "../include/Player.h"
#include "../include/Room.h"
#include "../include/View.h"

typedef struct _level {
	int width;
	int height;
	Room** rooms;
	int numRooms;
	Player* player;
	View* view;

	//Monster
	//Items
	//Platforms
} Level;

//Level functions
Level* createLevel(int width, int height, int numRooms, View* view);
int drawLevel(Level* lvl);
int roomIsInsideOfView(Room* room, View* view);

#endif 