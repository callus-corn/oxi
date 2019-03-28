#pragma once

#include <memory>
#include "../i_game_observer.hpp"

namespace oxi 
{
	namespace scene
	{
		class ISceneSubject 
		{
		protected:
			std::shared_ptr<IGameObserver> game_observer;
		public:
			explicit ISceneSubject(std::shared_ptr<IGameObserver> constractor_game_observer)
			:game_observer(constractor_game_observer){}
			virtual ~ISceneSubject() {}
			virtual void run() {}
		};
	}
}