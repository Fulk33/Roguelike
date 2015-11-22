#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "../include/View.h"



#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 60

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
  	
  	View* view = createView(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    Level* lvl_1 = createLevel(60, 80, 3, view);

    centerViewOnPlayer(view, lvl_1->player);
    drawLevel(lvl_1, lvl_1->view);
  	
  	//MAIN GAMELOOP
  	int input;
  	while(isRunning) {
  		input = getInput();
  		switch(input) {
  			case 0: movePlayer(lvl_1->player, lvl_1->view, 0);
  					break;
  			case 1: movePlayer(lvl_1->player, lvl_1->view, 1);
  					break;
  			case 2: movePlayer(lvl_1->player, lvl_1->view, 2);
  					break;
  			case 3: movePlayer(lvl_1->player, lvl_1->view, 3);
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