#include "mock_object.hpp"
#include "Dxlib.h"

oxi::scene::game_object::MockObject::MockObject()
{
	fuga = LoadGraph("resources/test.png");
}

void oxi::scene::game_object::MockObject::draw()
{
	DrawGraph(0, 0, fuga, 0);
}

void oxi::scene::game_object::MockObject::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_X) > 0)
	{
		scene_observer->update("title");
	}
}