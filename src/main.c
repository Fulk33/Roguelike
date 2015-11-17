#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"
#include "../include/Room.h"

int main(int argc, char const *argv[])
{
	initscr();
	noecho();
  	curs_set(FALSE);  	
  	
  	//Initialising a Playerpointer and allocating Memory of the Structure Player
  	Player* p = createPlayer(5, 10);

  	mvaddch(p->x, p->y, p->symbol);

  	Room* r1 = createRoom(20, 20, 10, 15);
  	drawRoom(r1);
  	refresh();

  	getch();

  	endwin();
	return 0;
}