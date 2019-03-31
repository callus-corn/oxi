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
				virtual ~IGameObjectSubject() {}
				virtual void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_observer) {}
				virtual void run() {}
			};
		}
	}
}