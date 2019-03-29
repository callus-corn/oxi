#pragma once

#include "i_game_object.hpp"

namespace oxi
{
	namespace scene 
	{
		class IGameObjectFactory 
		{
		public:
			virtual std::vector<std::shared_ptr<IGameObject>> create(std::string scene_name) = 0;
		};
	}
}