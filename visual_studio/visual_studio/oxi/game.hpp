#pragma once

#include <memory>

namespace oxi 
{
	class IScene;
	class ISceneFactory;
	class IController;

	class Game
	{
	private:
		const std::shared_ptr<ISceneFactory> scene_factory_;
		const std::shared_ptr<IController> controller_;
	public:
		explicit Game(std::shared_ptr<ISceneFactory> scene_factory, std::shared_ptr<IController> controller);
		virtual ~Game() {}
		void start();
	};
}