#pragma once

#include <memory>
#include "../../i_controllable.hpp"
#include "../i_game_object.hpp"
#include "../i_scene_observer.hpp"
#include "i_game_object_subject.hpp"
#include "collision_detection.hpp"
#include <vector>

namespace oxi
{
	namespace scene 
	{
		namespace game_object
		{
			class MockObject :public IGameObject,public IControllable,public IGameObjectSubject
			{
			private:
				Sound sound;
				Image image;
				std::shared_ptr<CollisionDetection> collision_detection;
				std::vector<Kind> collision_kinds{};
			public:
				MockObject();
				void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_observer) override { scene_observer = setted_scene_observer; }
				void run() override;
				void collisionDetect(std::shared_ptr<ICollisionDetection> obstacle_collision_detection) override;
				void collision() override;
				std::shared_ptr<ICollisionDetection> getCollisionDetection() override { return collision_detection; }
				void draw() override;
				void update(std::map<Key, Frame> input) override;
				bool isDisposable() override { return false; }
			};
		}
	}
}