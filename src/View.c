#include <stdlib.h>
#include "../include/View.h"
#include "../include/Player.h"

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