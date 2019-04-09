#pragma once

#include "../../i_controllable.hpp"
#include "../i_game_object.hpp"
#include "i_game_object_subject.hpp"
#include "collision_detection.hpp"
#include <string>

using Sound = int;
using Image = int;

namespace oxi 
{
	namespace scene
	{
		namespace game_object
		{
			class TitleBack :public IGameObject, public IControllable,public IGameObjectSubject
			{
			private:
				Sound sound;
				Image image;
				std::shared_ptr<CollisionDetection> collision_detection;
			public:
				TitleBack();
				void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_observer) override { scene_observer = setted_scene_observer; }
				void draw() override;
				std::shared_ptr<ICollisionDetection> getCollisionDetection() override { return collision_detection; }
				void update(std::map<Key,Frame> input) override;
			};
		}
	}
}