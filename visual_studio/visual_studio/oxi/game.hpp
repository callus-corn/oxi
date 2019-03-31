#pragma once

#include <memory>
#include <cassert>
#include "i_game_observer.hpp"
#include "i_controller.hpp"

namespace oxi 
{
	class IScene;
	class ISceneFactory;

	class Game:public IGameObserver ,public std::enable_shared_from_this<Game>
	{
	private:
		std::shared_ptr<IScene> scene;
		std::shared_ptr<ISceneFactory> scene_factory;
	public:
		explicit Game(std::shared_ptr<ISceneFactory> constractor_scene_factory);
		virtual ~Game();
		void start(std::shared_ptr<IController> controller);
		void update(std::string next_scene_name) override;
	};
}