#pragma once

#include <string>
#include "i_game_observer.hpp"

namespace oxi 
{
	class IScene;

	class ISceneFactory 
	{
	public:
		virtual std::shared_ptr<IScene> create(std::string scene_name)=0;
		virtual void setGameObserver(std::shared_ptr<IGameObserver> setted_game_obserer) {}
		virtual ~ISceneFactory() {}
	};
}