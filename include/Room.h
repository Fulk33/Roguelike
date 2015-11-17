#ifndef ROOM_H
#define ROOM_H

typedef struct Room{
	int x;
	int y;
	int width;
	int height;

} Room;

//Room Functions
Room* createRoom(int w, int h);
void deleteRoom(Room* room);

#endif 