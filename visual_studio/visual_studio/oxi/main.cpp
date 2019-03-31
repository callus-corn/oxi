#include "main.hpp"
#include "game.hpp"
#include "scene/scene_factory.hpp"
#include "scene/game_object/game_object_factory.hpp"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto game_object_factory = std::make_shared <oxi::scene::game_object::GameObjectFactory>();
	auto scene_factory = std::make_shared<oxi::scene::SceneFactory>(game_object_factory);
	auto game = std::make_shared<oxi::Game>(std::static_pointer_cast<oxi::ISceneFactory>(scene_factory));

	game->start();

	return 0;
}