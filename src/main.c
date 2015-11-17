#include <stdio.h>
#include <ncurses.h>

int main(int argc, char const *argv[])
{
	initscr();
	  noecho();
  	curs_set(FALSE);
  	sleep(1);
  	endwin();
	return 0;
}