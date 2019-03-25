#include "game.hpp"
#include "DxLib.h"

oxi::Game::Game()
{
	SetMainWindowText("oxi");
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);
	SetWindowSizeChangeEnableFlag(FALSE);

	if (DxLib_Init() == -1) { return; }
}

oxi::Game::~Game() 
{
	DxLib_End();
}

void oxi::Game::start() const
{
	WaitKey();
}