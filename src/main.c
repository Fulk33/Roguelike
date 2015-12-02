#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "../include/View.h"

#define WINDOW_WIDTH 95
#define WINDOW_HEIGHT 28

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
    Level* lvl_1 = createLevel(60, 80, 3);

    centerViewOnPlayer(view, lvl_1->player);
    renderView(lvl_1, view);
  	
  	//MAIN GAMELOOP
  	int input;
  	while(isRunning) {
  		renderView(lvl_1, view);
  		input = getInput();
  		switch(input) {
  			case 0: movePlayer(lvl_1->player, 0);
  					view->y--;
  					break;
  			case 1: movePlayer(lvl_1->player, 1);
  					view->x++;
  					break;
  			case 2: movePlayer(lvl_1->player, 2);
  					view->y++;
  					break;
  			case 3: movePlayer(lvl_1->player, 3);
  					view->x--;
  					break;
  			case 4: isRunning = 0;
  					break;
  			case -1: isRunning = 0;
  					break;
  			
  		}

  		

  		clear();
  	}

  	endwin();
	return 0;
}