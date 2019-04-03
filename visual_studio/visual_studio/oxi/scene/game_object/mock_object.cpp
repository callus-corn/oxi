#include "mock_object.hpp"
#include "Dxlib.h"

oxi::scene::game_object::MockObject::MockObject():position(640-50,360-50)
{
	image = LoadGraph("resources/none.png");
}

void oxi::scene::game_object::MockObject::run()
{
	position.addY(2);
}

void oxi::scene::game_object::MockObject::draw()
{
	DrawGraph(position.getX(), position.getY(), image, 0);
}

void oxi::scene::game_object::MockObject::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_X) > 0)
	{
		scene_observer->update("title");
	}
	if (input.at(KEY_INPUT_RIGHT) > 0) 
	{
		position.addX(10);
	}
	if (input.at(KEY_INPUT_LEFT) > 0)
	{
		position.addX(-10);
	}
	if (input.at(KEY_INPUT_UP) > 0)
	{
		position.addY(-10);
	}
	if (input.at(KEY_INPUT_DOWN) > 0)
	{
		position.addY(10);
	}
}