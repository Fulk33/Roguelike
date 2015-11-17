#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"

int main(int argc, char const *argv[])
{
	initscr();
	noecho();
  	curs_set(FALSE);
<<<<<<< HEAD
  	
  	
  	//Initialising a Playerpointer and allocating Memory of the Structure Player
=======

>>>>>>> 2a094fe6dd983aeb1be2c1d0fbe10eacda96e958
  	Player* p = (Player*)malloc(sizeof(Player));
  	p->x = 5;										//Position x
  	p->y = 10;										//Position y
  	p->symbol = 'Q';								//Symbol

  	mvaddch(p->x, p->y, p->symbol);
  	refresh();

  	getch();

  	endwin();
	return 0;
}