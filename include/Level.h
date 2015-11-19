#ifndef LEVEL_H
#define LEVEL_H

typedef struct _level {
	int width;
	int height;
	Room* rooms;
	int numRooms;
	Player* player;

	//Monster
	//Items
	//Platforms
} Level;

#endif 