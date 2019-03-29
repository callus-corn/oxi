#include "scene_factory.hpp"
#include "title_scene.hpp"
#include "play_ground_scene.hpp"
#include "title_scene.hpp"
#include "i_game_object_factory.hpp"

void oxi::scene::SceneFactory::initialize(std::shared_ptr<IGameObserver> initial_game_observer)
{
	game_observer = initial_game_observer;
}

std::shared_ptr<oxi::IScene> oxi::scene::SceneFactory::create(std::string scene_name)
{
	std::vector<std::shared_ptr<IGameObject>> game_objects{ game_object_factory->create(scene_name) };
	if (scene_name == "title") 
	{
		return std::make_shared<TitleScene>(game_observer,game_objects);
	}
	else if (scene_name == "play_ground")
	{
		return std::make_shared<PlayGroundScene>(game_observer,game_objects);
	}
	else
	{
		return std::make_shared<PlayGroundScene>(game_observer,game_objects);
	}
}
