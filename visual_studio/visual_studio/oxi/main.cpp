#include "main.hpp"
#include "game.hpp"
#include "scene/scene_factory.hpp"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::shared_ptr<oxi::scene::SceneFactory> sceneFactory = std::make_shared<oxi::scene::SceneFactory>();
	std::shared_ptr<oxi::Game> game = std::make_shared<oxi::Game>(std::static_pointer_cast<oxi::ISceneFactory>(sceneFactory));
	sceneFactory->initialize(std::static_pointer_cast<oxi::IGameObserver>(game));

	game->start();

	return 0;
}