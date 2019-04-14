#pragma once

#include <string>
#include <memory>
#include "i_game_object.hpp"

namespace oxi
{
	namespace scene 
	{
		class ISceneObserver
		{
		public:
			virtual void update(std::string next_scene_name) {}
			virtual void addGameObject(std::shared_ptr<IGameObject> game_object) {}
		};
	}
}