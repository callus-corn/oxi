#include "controller.hpp"
#include "DXlib.h"

void oxi::controller::Controller::update()
{
	char key[256]{};

	GetHitKeyStateAll(key);
	for (int i = 0; i < 256; i++)
	{
		if (key[i] == 1) 
		{
			key_map[i] += 1;
		}
		else 
		{
			key_map[i] = 0;
		}
	}

	controllable->update(key_map);

}