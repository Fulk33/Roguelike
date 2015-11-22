#include <stdlib.h>
#include <ncurses.h>
#include "../include/View.h"

View* createView(int x, int y, int width, int height){
	View* newView;

	newView = (View*)malloc(sizeof(View));
	newView->x = x;
	newView->y = y;
	newView->width = width;
	newView->height = height;

	return newView;
}

int centerViewOnPlayer(View* view, Player* player){
	view->x = player->x - view->width/2;
	view->y = player->y - view->height/2;

	return 1;
}
/**
 * This will draw the symbol of the player
 * @param  p The pointer to the player
 * @return   1
 */
int drawPlayer(Player* p, View* view){
	mvaddch(p->y-view->y, p->x-view->x, p->symbol);
	return 1;
}

/**
 * This function draws a room
 * @param	pointer to a room
 * @return 	1
 */
int drawRoom(Room* room, View* view) {
	for (int i = 0; i < room->width; i++) {
		for (int j = 0; j < room->height; j++) {
			if((i==0 && j==0) || (i==0 && j==room->height-1) || (i==room->width-1 && j==0) || (i==room->width-1 && j==room->height-1)){
				mvaddch(room->y+j-view->y, room->x+i-view->x, '+');
			} else if(i==0 || i == room->width-1){
				mvaddch(room->y+j-view->y, room->x+i-view->x, '|');
			} else if(j==0 || j == room->height-1){
				mvaddch(room->y+j-view->y, room->x+i-view->x, '-');
			} else
			mvaddch(room->y+j-view->y, room->x+i-view->x, '.');
		}
	}
	return 1;
}

int roomIsInsideOfView(Room* room, View* view){
	if(view->x < room->x + room->width && 
		view->x + view->width > room->x &&
		view->y < room->y + room->height &&
		view->height + view->y > room->y) {
		return 1;
	} else {
		return 0;
	}
}

int renderbox(int x, int y, int width, int height) {
	mvaddch(0, 0, '+');
	for (int i = 1; i < width-1; i++) {
		mvaddch(0, i, '-');
	}
	mvaddch(0, width, '+');
	for (int i = 1; i < height; i++) {
		mvaddch(i, 0, '|');
		mvaddch(i, width, '|');
	}
	mvaddch(height, 0, '+');
	for (int i = 1; i < width-1; i++) {
		mvaddch(height, i, '-');
	}
	mvaddch(height, width, '+');
}

int renderView(Level* lvl, View* view) {
	int i;
	for(i = 0; i < lvl->numRooms; i++){
		if(roomIsInsideOfView(lvl->rooms[i], view)) {
			drawRoom(lvl->rooms[i], view);
		}
	}

	drawPlayer(lvl->player, view);
	
	//renderbox(view->x * -1, view->y * -1, lvl->width, lvl->height);

	renderbox(0, 0, view->width, view->height);
}