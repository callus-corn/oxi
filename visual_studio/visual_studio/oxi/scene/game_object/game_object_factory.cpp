#include "game_object_factory.hpp"
#include "title_back.hpp"

std::vector<std::shared_ptr<oxi::scene::IGameObject>> oxi::scene::game_object::GameObjectFactory::create(std::string scene_name)
{
	if (scene_name == "title") 
	{
		return std::vector<std::shared_ptr<IGameObject>>
		{
			std::static_pointer_cast<IGameObject>(std::make_shared<TitleBack>())
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
