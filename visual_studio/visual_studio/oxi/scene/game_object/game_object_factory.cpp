#include "game_object_factory.hpp"
#include "title_back.hpp"

std::vector<std::shared_ptr<oxi::scene::IGameObject>> oxi::scene::game_object::GameObjectFactory::create(std::string scene_name)
{
	if (scene_name == "title") 
	{
		return std::vector<std::shared_ptr<IGameObject>>
		{
			std::static_pointer_cast<IGameObject>(std::make_shared<TitleBack>(scene_observer))
		};
	}
	else if(scene_name == "play_ground")
	{
		return std::vector<std::shared_ptr<IGameObject>>();
	}
	else 
	{
		return std::vector<std::shared_ptr<IGameObject>>();
	}
}

void oxi::scene::game_object::GameObjectFactory::setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_obserer)
{
	scene_observer = setted_scene_obserer;
}
