#include <stdlib.h>
#include <ncurses.h>
#include "../include/Level.h"
#include "../include/Player.h"
#include "../include/Room.h"


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

int drawLevel(Level* lvl) {
	int i;
	for(i = 0; i < lvl->numRooms; i++){
		drawRoom(lvl->rooms[i]);
	}

	drawPlayer(lvl->player);

	for (int i = 0; i < lvl->width; i++) {
		for (int j = 0; j < lvl->height; j++) {
			if((i==0 && j==0) || (i==0 && j==lvl->height-1) || (i==lvl->width-1 && j==0) || (i==lvl->width-1 && j==lvl->height-1)){
				mvaddch(j, i, '+');
			} else if(i==0 || i == lvl->width-1){
				mvaddch(j, i, '|');
			} else if(j==0 || j == lvl->height-1){
				mvaddch(j, i, '-');
			}
		}
	}
}