#include "game.hpp"
#include "i_scene_factory.hpp"
#include "i_scene.hpp"
#include "DxLib.h"

namespace 
{
	const std::string first_scene_name = "title";
}

oxi::Game::Game(std::shared_ptr<ISceneFactory> constractor_scene_factory)
	:scene_factory(constractor_scene_factory)
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

void oxi::Game::start()
{
	scene = scene_factory->create(first_scene_name);
	while (ProcessMessage() == 0) 
	{
		scene->run();
	}
}

void oxi::Game::update(std::string nextSceneName)
{
	scene = scene_factory->create(nextSceneName);
}