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
 * This will move the player in a given direction
 * @param  p   The pointer to the player
 * @param  dir The direction (0: up; 1: right; 2: down; 3: left)
 * @return     1
 */
int movePlayer(Player* p, int dir){

	switch(dir) {
		case 0:	
				p->y--;
				
				break;
		case 1: 
				p->x++;
				
				break;
		case 2: 
				p->y++;
				break;
		case 3: 
				p->x--;
				break;
		default:

				break;
	}

	return 1;
}
//TODO Delete_player because else hässliche Memory leaks