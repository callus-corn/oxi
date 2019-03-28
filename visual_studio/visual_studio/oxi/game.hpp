#pragma once

#include <memory>
#include "i_game_observer.hpp"

namespace oxi 
{
	class IScene;
	class ISceneFactory;

	class Game:public IGameObserver 
	{
	private:
		std::shared_ptr<IScene> scene;
		std::shared_ptr<ISceneFactory> scene_factory;
	public:
		explicit Game(std::shared_ptr<ISceneFactory> constractor_scene_factory);
		virtual ~Game();
		void start();
		void update(std::string next_scene_name) override;
	};
}