#include "title_back.hpp"
#include "Dxlib.h"

oxi::scene::game_object::TitleBack::TitleBack():position(0,0)
{
	image = LoadGraph("resources/title.png");
	sound = LoadSoundMem("resources/theme.mp3");
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
}

void oxi::scene::game_object::TitleBack::draw()
{
	DrawGraph(position.getX(),position.getY(),image,0);
}

void oxi::scene::game_object::TitleBack::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_Z) > 0)
	{
		StopSoundMem(sound);
		scene_observer->update("play_ground");
	}
}
