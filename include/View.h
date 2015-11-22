#ifndef VIEW_H
#define VIEW_H

#include "../include/Level.h"

typedef struct _view {
	int x;
	int y;
	int width;
	int height;
} View;

//View Functions
View* createView(int x, int y, int width, int height);
int centerViewOnPlayer(View* view, Player* player);
int roomIsInsideOfView(Room* room, View* view);
int renderView(Level* lvl, View* view);
int drawRoom(Room* room, View* view);
int drawPlayer(Player* p, View* view);
int renderbox(int x, int y, int width, int height);


#endif