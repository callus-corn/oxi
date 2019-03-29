#pragma once

#include <memory>
#include <vector>
#include "../i_game_object_factory.hpp"
#include "../i_game_object.hpp"

namespace oxi
{
	namespace scene 
	{
		namespace game_object 
		{
			class GameObjectFactory :public IGameObjectFactory
			{
			public:
				std::vector<std::shared_ptr<IGameObject>> create(std::string scene_name) override;
			};
		}
	}
}