#include "title_back.hpp"
#include "Dxlib.h"
#include <memory>
#include "position.hpp"

namespace 
{
	static const Kind kind = oxi::scene::game_object::ObjectClassification::back_ground;
	static const int collision_detection_x_length = 0;
	static const int collision_detection_y_length = 0;
	static const oxi::scene::game_object::Position initial_position(0, 0);
}

oxi::scene::game_object::TitleBack::TitleBack()
	:collision_detection(std::make_shared<CollisionDetection>(kind,collision_detection_x_length,collision_detection_y_length,initial_position))
{
	image = LoadGraph("resources/title.png");
	sound = LoadSoundMem("resources/theme.mp3");
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
}

void oxi::scene::game_object::TitleBack::draw()
{
	DrawGraph(collision_detection->getX(),collision_detection->getY(),image,0);
}

void oxi::scene::game_object::TitleBack::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_Z) > 0)
	{
		StopSoundMem(sound);
		scene_observer->update("play_ground");
	}
}
