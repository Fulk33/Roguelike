#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"

#define PLAYER_SYMBOL 'Q'

/**
 * This will create an instance of Player
 * @param  x The x-Coordinate
 * @param  y The y-Coordinate
 * @return   pointer to the Player
 */
Player* createPlayer(int x, int y) {

	Player* newPlayer;
	newPlayer = (Player*)malloc(sizeof(Player));

	newPlayer->x = x;
	newPlayer->y = y;
	newPlayer->symbol = PLAYER_SYMBOL;
	newPlayer->ground = '.';

	return newPlayer;
}

/**
 * This will draw the symbol of the player
 * @param  p The pointer to the player
 * @return   1
 */
int drawPlayer(Player* p){
	mvaddch(p->x, p->y, p->symbol);
	return 1;
}

/**
 * This will move the player in a given direction
 * @param  p   The pointer to the player
 * @param  dir The direction (0: up; 1: right; 2: down; 3: left)
 * @return     1
 */
int movePlayer(Player* p, int dir){

	switch(dir) {
		case 0:	mvaddch(p->x, p->y, p->ground);
				p->x--;
				drawPlayer(p);
				break;
		case 1: mvaddch(p->x, p->y, p->ground);
				p->y++;
				drawPlayer(p);
				break;
		case 2: mvaddch(p->x, p->y, p->ground);
				p->x++;
				drawPlayer(p);
				break;
		case 3: mvaddch(p->x, p->y, p->ground);
				p->y--;
				drawPlayer(p);
				break;



		default:
				break;
	}

	return 1;
}

Player* spawnPlayer(Room* rooms, int numRooms) {
	//The player will always be spawed in the first room in the array
	
	Player* newPlayer;

	int x = rooms[0]->x + 2; //change this later
	int y = rooms[0]->y + 2; 

	newPlayer = (Player*)createPlayer(x, y);

	return newPlayer;
}