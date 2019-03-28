#include "scene_factory.hpp"
#include "title_scene.hpp"
#include "play_ground_scene.hpp"
#include "title_scene.hpp"

void oxi::scene::SceneFactory::initialize(std::shared_ptr<IGameObserver> initial_game_observer)
{
	game_observer = initial_game_observer;
	scene_map.insert(std::make_pair("title", std::make_shared<TitleScene>(game_observer)));
	scene_map.insert(std::make_pair("play_ground", std::make_shared<PlayGroundScene>(game_observer)));
}

std::shared_ptr<oxi::IScene> oxi::scene::SceneFactory::create(std::string scene_name)
{
	return scene_map.at(scene_name);
}
