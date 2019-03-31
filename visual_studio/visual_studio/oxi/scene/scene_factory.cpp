#include "scene_factory.hpp"
#include "title_scene.hpp"
#include "play_ground_scene.hpp"
#include "title_scene.hpp"
#include "i_game_object_factory.hpp"

void oxi::scene::SceneFactory::setGameObserver(std::shared_ptr<IGameObserver> setted_game_observer)
{
	game_observer = setted_game_observer;
}

std::shared_ptr<oxi::IScene> oxi::scene::SceneFactory::create(std::string scene_name)
{
	std::vector<std::shared_ptr<IGameObject>> game_objects{ game_object_factory->create(scene_name) };
	if (scene_name == "title") 
	{
		auto scene = std::make_shared<TitleScene>(game_observer, game_objects);
		game_object_factory->setSceneObserver(std::static_pointer_cast<ISceneObserver>(scene));
		return scene;
	}
	else if (scene_name == "play_ground")
	{
		auto scene = std::make_shared<PlayGroundScene>(game_observer,game_objects);
		game_object_factory->setSceneObserver(std::static_pointer_cast<ISceneObserver>(scene));
		return scene;
	}
	else
	{
		auto scene = std::make_shared<PlayGroundScene>(game_observer, game_objects);
		game_object_factory->setSceneObserver(std::static_pointer_cast<ISceneObserver>(scene));
		return scene;
	}
}
