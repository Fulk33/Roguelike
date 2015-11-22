#include <stdlib.h>
#include <ncurses.h>
#include "../include/Room.h"

#define smallSize 5
#define mediumSize 13
#define largeSize 25

#define margin 8

/**
 * This will create a Room
 * @param	x-coordinates in the window
 * @param	y-coordinates in the window
 * @param	width of the Room
 * @param	height of the room
 * @return	the pointer newRoom
 */			
Room* createRoom(int x, int y, int w, int h) { 
	Room* newRoom;
	newRoom = (Room*)malloc(sizeof(Room));
	newRoom->x = x;
	newRoom->y = y;
	newRoom->width = w;
	newRoom->height = h;

	return newRoom;
}

/**
 * Deletes a Room
 * @param	pointer to a room
 * @return  1
 */
int deleteRoom(Room* room) {
	free(room);
	return 1;
}

 
Room** generateRooms(int numRooms, int levelWidth, int levelHeight) {
	int i, j, k, l;
	int rSize, rWidth, rHeight, rIndex, canBePlaced;
	int possiblePositions [levelHeight*levelWidth][2];
	int foundPositions;
	Room** rooms;

	rooms = (Room**)malloc(sizeof(Room*)*numRooms);

	//for every room in the level
	for(i = 0; i < numRooms; i++) {
		foundPositions = 0;
		//Generate size of room 5 13 25
		rSize = rand() % 3;
		switch(rSize){
			case 0: rHeight = rand() % 5 + smallSize;
					rWidth = rand() % 5 + smallSize;
					break;
			case 1: rHeight = rand() % 7 + mediumSize;
					rWidth = rand() % 7 + mediumSize;
					break;
			case 2: rHeight = rand() % 9 + largeSize;
					rWidth = rand() % 9 + largeSize;
					break;
		}
		//Generate Coordinates where a room whith this size could be placed
		for (j = 0; j < levelHeight; j++) {
			for (k = 0;  k < levelWidth; k++) {
				canBePlaced = checkForSpace(j, k, rWidth, rHeight, rooms, i);
				if(canBePlaced) {
					//room could be placed at position j, k
					possiblePositions[foundPositions][0] = j;
					possiblePositions[foundPositions][1] = k;
					foundPositions++;
				}
			}		
		}
		//Choose coordinates randomly
		 
		rIndex = rand() % foundPositions;
		
		//Place the room
		
		rooms[i] = createRoom(possiblePositions[rIndex][0], possiblePositions[rIndex][1], rWidth, rHeight);
	}
	
	return rooms;
}

int checkForSpace(int x, int y, int width, int height, Room** rooms, int numRooms) {
	int i;
	for(i = 0; i < numRooms; i++){
		if(x < (rooms[i]->x-margin) + (rooms[i]->width+margin) && 
			x + width > (rooms[i]->x-margin) &&
			y < (rooms[i]->y-margin) + (rooms[i]->height+margin) &&
			height + y > (rooms[i]->y-margin)) {
			return 0;
		}
	}
	return 1;
}

Player* spawnPlayer(Room** rooms, int numRooms) {
	//The player will always be spawed in the first room in the array
	
	Player* newPlayer;

	int x = rooms[0]->x + 2; //change this later
	int y = rooms[0]->y + 2; 

	newPlayer = (Player*)createPlayer(x, y);

	return newPlayer;
}