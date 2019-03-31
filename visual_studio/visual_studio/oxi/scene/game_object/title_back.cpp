#include "title_back.hpp"
#include "Dxlib.h"

oxi::scene::game_object::TitleBack::TitleBack(std::shared_ptr<ISceneObserver> constractor_scene_observer) :IGameObjectSubject(constractor_scene_observer)
{
	fuga = LoadGraph("resources/title.png");
	hoge = LoadSoundMem("resources/theme.mp3");
	PlaySoundMem(hoge, DX_PLAYTYPE_LOOP);
}

void oxi::scene::game_object::TitleBack::draw()
{
	DrawGraph(0,0,fuga,0);
}

void oxi::scene::game_object::TitleBack::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_Z) > 0)
	{
		scene_observer->update("play_ground");
	}
}
