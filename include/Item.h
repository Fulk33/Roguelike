#ifndef ITEM_H
#define ITEM_H

typedef struct _item{
	char name[MAX_STRING];
	char desc[MAX_DESC];
	int id; //id  of item
} Item;

#endif