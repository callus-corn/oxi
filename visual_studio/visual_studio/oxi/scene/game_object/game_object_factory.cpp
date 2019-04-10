#include "game_object_factory.hpp"
#include "title_back.hpp"
#include "mock_object.hpp"
#include "mock_ground.hpp"
#include "mock_enemy.hpp"
#include <algorithm>

std::vector<std::shared_ptr<oxi::scene::IGameObject>> oxi::scene::game_object::GameObjectFactory::create(std::string scene_name)
{
	if (scene_name == "title") 
	{
		auto controllable = std::make_shared<TitleBack>();
		controller->setControllable(std::static_pointer_cast<IControllable>(controllable));
		game_objects = std::vector<std::shared_ptr<IGameObject>>
		{
			std::static_pointer_cast<IGameObject>(controllable)
		};
		return game_objects;
	}
	else if(scene_name == "play_ground")
	{
		auto controllable = std::make_shared<MockObject>();
		controller->setControllable(std::static_pointer_cast<IControllable>(controllable));
		game_objects = std::vector<std::shared_ptr<IGameObject>>
		{
			std::static_pointer_cast<IGameObject>(controllable),
			std::static_pointer_cast<IGameObject>(std::make_shared<MockGround>()),
			std::static_pointer_cast<IGameObject>(std::make_shared<MockEnemy>())
		};
		return game_objects;
	}
	else 
	{
		auto controllable = std::make_shared<MockObject>();
		controller->setControllable(std::static_pointer_cast<IControllable>(controllable));
		game_objects = std::vector<std::shared_ptr<IGameObject>>
		{
			std::static_pointer_cast<IGameObject>(controllable),
			std::static_pointer_cast<IGameObject>(std::make_shared<MockGround>()),
			std::static_pointer_cast<IGameObject>(std::make_shared<MockEnemy>())
		};
		return game_objects;
	}
}

void oxi::scene::game_object::GameObjectFactory::setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_obserer)
{
	std::for_each(game_objects.begin(), game_objects.end(), [&setted_scene_obserer](std::shared_ptr<IGameObject> game_object) {
		if (std::dynamic_pointer_cast<IGameObjectSubject>(game_object)) 
		{
			std::dynamic_pointer_cast<IGameObjectSubject>(game_object)->setSceneObserver(setted_scene_obserer);
		}
	});
}
