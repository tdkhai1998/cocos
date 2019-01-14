#include "Maps.h"

vector<Sprite*> Maps::selectedMap(int type)
{
	if (type == 0) {
		return mapNomal[random() % 4]();
	}
	else {
		return mapSpecial[random() % 4]();
	}
}

Maps * Maps::getMap()
{
	if (singleton == NULL)
	{
		return singleton = new Maps();
	}
	return singleton;
}

Maps::~Maps()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}
