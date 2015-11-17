#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/Player.h"

int main(int argc, char const *argv[])
{
	initscr();
	noecho();
  	curs_set(FALSE);

  	Player* p = (Player*)malloc(sizeof(Player));
  	p->x = 5;
  	p->y = 10;
  	p->symbol = 'Q';

  	mvaddch(p->x, p->y, p->symbol);
  	refresh();

  	getch();

  	endwin();
	return 0;
}