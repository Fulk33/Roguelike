#ifndef ROOM_H
#define ROOM_H

typedef struct _Room{
	int x;
	int y;
	int width;
	int height;

} Room;

//Room Functions
Room* createRoom(int x, int y, int w, int h);
int deleteRoom(Room* room);
int drawRoom(Room* room);
Room** generateRooms(int numRooms, int levelWidth, int levelHeight);
int checkForSpace(int x, int y, int width, int height, Room** rooms, int numRooms);

#endif 