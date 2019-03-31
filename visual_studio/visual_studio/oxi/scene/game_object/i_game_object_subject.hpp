#pragma once

#include <memory>
#include "../i_scene_observer.hpp"

namespace oxi
{
	namespace scene 
	{
		namespace game_object
		{
			class IGameObjectSubject 
			{
			protected:
				std::shared_ptr<ISceneObserver> scene_observer;
			public:
				IGameObjectSubject(std::shared_ptr<ISceneObserver> constractor_scene_observer):scene_observer(constractor_scene_observer) {}
				virtual void addObserver() {}
				virtual void run() {}
			};
		}
	}
}