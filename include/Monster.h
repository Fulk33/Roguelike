#ifndef MONSTER_H
#define MONSTER_H

typedef struct _monster{
	int x;
	int y;
	char name[MAX_STRING]; //Kind of monster or name
	char symbol; //symbol of monster e.g. 'M'
	int attk;
	int health;
	int def;
	float speed;
	Item* item;
int
} Monster;

#endif