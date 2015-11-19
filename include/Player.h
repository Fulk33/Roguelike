#ifndef PLAYER_H
#define PLAYER_H

#include "../include/Room.h"

//Defining a new Type with struct.
typedef struct _Player { //Called Player
	int x;				//x Position and y Position
	int y;
	char symbol;		//Symbol of the player e.g. 'Q'
	char ground;
} Player;

//Player Functions
Player* createPlayer(int x, int y);
int drawPlayer(Player* p);
int movePlayer(Player* p, int dir);
Player* spawnPlayer(Room** rooms, int numRooms);

#endif 