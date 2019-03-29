#pragma once

#include "../i_scene_factory.hpp"
#include "../i_game_observer.hpp"

namespace oxi 
{
	namespace scene 
	{
		class IGameObjectFactory;

		class SceneFactory :public ISceneFactory
		{
		private:
			std::shared_ptr<IGameObserver> game_observer;
			std::shared_ptr<IGameObjectFactory> game_object_factory;
		public:
			explicit SceneFactory(std::shared_ptr<IGameObjectFactory> constractor_game_object_factory)
				:game_object_factory(constractor_game_object_factory) {}
			void initialize(std::shared_ptr<IGameObserver> initial_game_observer);
			std::shared_ptr<IScene> create(std::string scene_name) override;
		};
	}
}