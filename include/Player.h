#ifndef PLAYER_H
#define PLAYER_H
//Defining a new Type with struct.
typedef struct Player { //Called Player
	int x;				//x Position and y Position
	int y;
	char symbol;		//Symbol of the player e.g. 'Q'
	char prevChar;
} Player;

//Player Functions
Player* createPlayer(int x, int y);
int movePlayer(Player* p, int dir);

#endif 