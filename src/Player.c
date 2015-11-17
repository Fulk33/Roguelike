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
	newPlayer->ground = '.';
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