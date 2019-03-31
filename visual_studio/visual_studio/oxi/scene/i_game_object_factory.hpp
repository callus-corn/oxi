#pragma once

#include "i_scene_observer.hpp"
#include "i_game_object.hpp"

namespace oxi
{
	namespace scene 
	{
		class IGameObjectFactory 
		{
		public:
			virtual void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_obserer) {}
			virtual std::vector<std::shared_ptr<IGameObject>> create(std::string scene_name) = 0;
		};
	}
}