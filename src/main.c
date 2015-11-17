#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"
#include "../include/Room.h"


enum INPUT {
	up,
	right,
	down,
	left
};

int getInput(){
	int c = getch();
	switch(c){
		case KEY_UP: return 0;
		case KEY_RIGHT: return 1;
		case KEY_DOWN: return 2;
		case KEY_LEFT: return 3;
		case 'x': return 4;
		
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	//Initialisierung/////////////////////
	initscr();
	noecho();
  	curs_set(FALSE);

	keypad(stdscr, TRUE); //sets "using-keypad" to true
  	int isRunning = 1; 	
  	//////////////////////////////////////
    clear();
  	//Initialising a Playerpointer and allocating Memory of the Structure Player
  	Player* p = createPlayer(5, 10);
    drawPlayer(p);

  	Room* r1 = createRoom(20, 20, 15, 10);
  	drawRoom(r1);
  	
  	int input;



  	while(isRunning) {
  		input = getInput();
  		switch(input) {
  			case 0: movePlayer(p, 0);
  					break;
  			case 1: movePlayer(p, 1);
  					break;
  			case 2: movePlayer(p, 2);
  					break;
  			case 3: movePlayer(p, 3);
  					break;
  			case 4: isRunning = 0;
  					break;
  			case -1: isRunning = 0;
  					break;
  			
  		}

  		
  		refresh();
  	}

  	endwin();
	return 0;
}