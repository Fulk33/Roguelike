#include <stdlib.h>
#include <ncurses.h>
#include "../include/Level.h"

Level* createLevel(int width, int height, int numRooms){

	Level* newLevel;

	newLevel = (Level*)malloc(sizeof(Level));

	newLevel->width = width;
	newLevel->height = height;
	newLevel->numRooms = numRooms;

	Room** newRooms = generateRooms(numRooms, width, height);
	newLevel->rooms = newRooms;

	Player* newPlayer = spawnPlayer(newLevel->rooms, numRooms);
	newLevel->player = newPlayer;


	return newLevel;
}

//TODO DeleteLevel weil sonst hässliches Memory leak

