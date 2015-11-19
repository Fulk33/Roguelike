#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "../include/Player.h"
#include "../include/Room.h"
#include "../include/Level.h"


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

  	srand ( time(NULL) );

	keypad(stdscr, TRUE); //sets "using-keypad" to true
  	int isRunning = 1; 	
  	//////////////////////////////////////
    clear();
  	
    Level *l01 = createLevel(60, 80, 10);
    drawLevel(l01);
  	
  	//MAIN GAMELOOP
  	int input;
  	while(isRunning) {
  		input = getInput();
  		switch(input) {
  			case 0: movePlayer(l01->player, 0);
  					break;
  			case 1: movePlayer(l01->player, 1);
  					break;
  			case 2: movePlayer(l01->player, 2);
  					break;
  			case 3: movePlayer(l01->player, 3);
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