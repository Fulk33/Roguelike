#ifndef VIEW_H
#define VIEW_H

#include "../include/Player.h"

typedef struct _view {
	int x;
	int y;
	int width;
	int height;
} View;

//View Functions
View* createView(int x, int y, int width, int height);
int centerViewOnPlayer(View* view, Player* player);

#endif