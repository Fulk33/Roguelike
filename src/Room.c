#include <stdlib.h>
#include <ncurses.h>
#include "../include/Room.h"

Room* createRoom(int x, int y, int w, int h) {
	Room* newRoom;
	newRoom = (Room*)malloc(sizeof(Room));
	newRoom->x = x;
	newRoom->y = y;
	newRoom->width = w;
	newRoom->height = h;

	return newRoom;
}

int deleteRoom(Room* room) {
	free(room);
	return 1;
}

int drawRoom(Room* room) {
	for (int i = 0; i < room->width; i++) {
		for (int j = 0; j < room->height; j++) {
			mvaddch(room->x+j, room->y+i, '.');
		}
	}
	return 1;
}