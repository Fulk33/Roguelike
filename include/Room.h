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
int deleteRoom(Room* room);
int drawRoom(Room* room);

#endif 