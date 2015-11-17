#include <stdlib.h>
#include "../include/Room.h"

Room* createRoom(int w, int h) {
	Room* newRoom;
	newRoom = (Room*)malloc(sizeof(Room));
	newRoom->width = w;
	newRoom->height = h;

	return newRoom;
}

void deleteRoom(Room* room) {
	free(room);
}