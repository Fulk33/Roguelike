#include <stdlib.h>
#include "../include/Player.h"

#define PLAYER_SYMBOL 'Q'

Player* createPlayer(int x, int y) {

	Player* newPlayer;
	newPlayer = (Player*)malloc(sizeof(Player));

	newPlayer->x = x;
	newPlayer->y = y;
	newPlayer->symbol = PLAYER_SYMBOL;
}