#pragma once

#include <map>
#include "../i_scene_factory.hpp"
#include "../i_game_observer.hpp"

namespace oxi 
{
	namespace scene 
	{
		class SceneFactory :public ISceneFactory
		{
		private:
			std::shared_ptr<IGameObserver> game_observer;
			std::map<std::string, std::shared_ptr<IScene>> scene_map;
		public:
			void initialize(std::shared_ptr<IGameObserver> initial_game_observer);
			std::shared_ptr<IScene> create(std::string scene_name) override;
		};
	}
}