#include "main.hpp"
#include "DxLib.h"
#include "game.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	oxi::Game game{};

	game.start();

	return 0;
}