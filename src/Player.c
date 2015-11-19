#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"

#define PLAYER_SYMBOL 'Q'
//To install DocBlockr press shift+ctrl+p and enter "Package Control: Install Package"
//hit enter, the type "DocBlockr" and hit enter again
//To use type /** over a function and hit tab/enter (also use tab (shift+tab) to move through the fields)

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

int drawPlayer(Player* p){
	mvaddch(p->x, p->y, p->symbol);
}

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