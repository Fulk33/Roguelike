#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"

#define PLAYER_SYMBOL 'Q'

Player* createPlayer(int x, int y) {

	Player* newPlayer;
	newPlayer = (Player*)malloc(sizeof(Player));

	newPlayer->x = x;
	newPlayer->y = y;
	newPlayer->symbol = PLAYER_SYMBOL;
	newPlayer->prevChar = ' ';
}

int movePlayer(Player* p, int dir){

	switch(dir) {
		case 0:	mvaddch(p->x, p->y, p->prevChar);
				p->prevChar = mvinch(p->y, p->x-1);
				p->x--;
				mvaddch(p->x, p->y, p->symbol);
				break;
		case 1: p->y++;
				break;
		case 2: p->x++;
				break;
		case 3: p->y--;
				break;
		default:
				break;
	}

	return 1;
}