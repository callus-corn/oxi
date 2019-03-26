#pragma once

#include "title_scene.hpp"
#include "play_ground_scene.hpp"
#include <memory>

namespace oxi 
{
	class Sequence 
	{
	private:
		const std::shared_ptr<IScene> title_scene{ new TitleScene(this) };
		const std::shared_ptr<IScene> play_ground_scene{ new PlayGroundScene(this) };
		std::shared_ptr<IScene> current_scene;
	public:
		Sequence():current_scene(title_scene){}
		virtual ~Sequence() {}
		void calculateScene() const { current_scene->calculate(); }
		void drawScene() const { current_scene->draw(); }
		void changePlayGroundScene() { current_scene = play_ground_scene; }
	};
}