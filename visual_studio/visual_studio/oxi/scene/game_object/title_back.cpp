#include "title_back.hpp"
#include "Dxlib.h"

oxi::scene::game_object::TitleBack::TitleBack()
{
	fuga = LoadGraph("resources/title.png");
	hoge = LoadSoundMem("resources/theme.mp3");
	PlaySoundMem(hoge, DX_PLAYTYPE_LOOP);
}

void oxi::scene::game_object::TitleBack::draw()
{
	DrawGraph(0,0,fuga,0);
}
