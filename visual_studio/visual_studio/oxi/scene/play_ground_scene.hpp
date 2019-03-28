#pragma once

#include "../i_scene.hpp"
#include "i_scene_subject.hpp"

namespace oxi 
{
	namespace scene 
	{
		class PlayGroundScene :public IScene ,public ISceneSubject
		{
		public:
			explicit PlayGroundScene(std::shared_ptr<IGameObserver> constractor_game_observer) :ISceneSubject(constractor_game_observer) {}
			void run() override;
		};
	}
}