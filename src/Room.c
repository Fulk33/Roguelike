#include <stdlib.h>
#include <ncurses.h>
#include "../include/Room.h"
/**
 * This will create a Room
 * @param	x-coordinates in the window
 * @param	y-coordinates in te window
 * @param	width of the Room
 * @param	height of te room
 * @return	returns the Pointer newRoom
 */			
Room* createRoom(int x, int y, int w, int h) { 
	Room* newRoom;
	newRoom = (Room*)malloc(sizeof(Room));
	newRoom->x = x;
	newRoom->y = y;
	newRoom->width = w;
	newRoom->height = h;

	return newRoom;
}
/**
 * Deletes the Room
 * @param	needs a room
 * @return  returns 1
 */
int deleteRoom(Room* room) {
	free(room);
	return 1;
}
/**
 * This function draws a room with the help of a 2-dimensional for-loop and some if-loops
 * @param	needs a room
 * @return 	returns 1
 */
int drawRoom(Room* room) {
	for (int i = 0; i < room->width; i++) {
		for (int j = 0; j < room->height; j++) {
			if((i==0 && j==0) || (i==0 && j==room->height-1) || (i==room->width-1 && j==0) || (i==room->width-1 && j==room->height-1)){
				mvaddch(room->x+j, room->y+i, '+');
			} else if(i==0 || i == room->width-1){
				mvaddch(room->x+j, room->y+i, '|');
			} else if(j==0 || j == room->height-1){
				mvaddch(room->x+j, room->y+i, '-');
			} else
			mvaddch(room->x+j, room->y+i, '.');
		}
	}
	return 1;
}