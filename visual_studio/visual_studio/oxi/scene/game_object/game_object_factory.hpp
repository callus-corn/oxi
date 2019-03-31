#pragma once

#include <memory>
#include <vector>
#include "../i_game_object_factory.hpp"
#include "../i_game_object.hpp"
#include "../i_scene_observer.hpp"

namespace oxi
{
	namespace scene 
	{
		namespace game_object 
		{
			class GameObjectFactory :public IGameObjectFactory
			{
			private:
				std::shared_ptr<ISceneObserver> scene_observer;
			public:
				std::vector<std::shared_ptr<IGameObject>> create(std::string scene_name) override;
				void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_obserer) override;
			};
		}
	}
}