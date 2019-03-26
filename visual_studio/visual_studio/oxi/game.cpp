#include "game.hpp"
#include "DxLib.h"
#include "sequence.hpp"

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
	while (ProcessMessage() == 0) 
	{
		sequence.calculateScene();
		sequence.drawScene();
	}
}