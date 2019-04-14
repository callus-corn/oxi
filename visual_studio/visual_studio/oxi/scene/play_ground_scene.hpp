#pragma once

#include <vector>
#include "../i_scene.hpp"
#include "i_scene_subject.hpp"
#include "i_game_object.hpp"
#include "i_scene_observer.hpp"

namespace oxi 
{
	namespace scene 
	{
		class PlayGroundScene :public IScene ,public ISceneSubject,public ISceneObserver
		{
		private:
			std::vector<std::shared_ptr<IGameObject>> game_objects;
		public:
			explicit PlayGroundScene(
				std::shared_ptr<IGameObserver> constractor_game_observer,
				std::vector<std::shared_ptr<IGameObject>> constractor_game_objects)
				:ISceneSubject(constractor_game_observer) ,
				game_objects(constractor_game_objects){}
			void run() override;
			void update(std::string next_scene_name) override { game_observer->update(next_scene_name); }
			void addGameObject(std::shared_ptr<IGameObject> game_object) override { game_objects.push_back(game_object); }
		};
	}
}