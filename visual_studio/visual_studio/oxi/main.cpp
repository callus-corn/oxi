#include "main.hpp"
#include "controller/controller.hpp"
#include "scene/object/spawn_factory.hpp"
#include "scene/object/gate_factory.hpp"
#include "scene/scene_factory.hpp"
#include "game.hpp"
#include "DxLib.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	auto controller = std::make_shared<oxi::controller::Controller>();
	auto spawn_factory = std::make_shared <oxi::scene::object::SpawnFactory>(controller);
	auto gate_factory = std::make_shared <oxi::scene::object::GateFactory>(controller);
	auto scene_factory = std::make_shared<oxi::scene::SceneFactory>(spawn_factory,gate_factory);
	auto game = std::make_shared<oxi::Game>(scene_factory,controller);

	game->start();

	return 0;
}