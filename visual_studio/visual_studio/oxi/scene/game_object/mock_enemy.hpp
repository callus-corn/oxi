#pragma once

#include "../i_game_object.hpp"
#include "collision_detection.hpp"
#include <vector>

using Frame = int;

namespace oxi
{
	namespace scene 
	{
		namespace game_object
		{
			class MockEnemy :public IGameObject
			{
				Frame frame;
				Image image;
				std::shared_ptr<CollisionDetection> collision_detection;
				std::vector<Kind> collision_kinds{};
			public:
				MockEnemy();
				void run() override;
				void collisionDetect(std::shared_ptr<ICollisionDetection> obstacle_collision_detection) override;
				void collision() override;
				std::shared_ptr<ICollisionDetection> getCollisionDetection() override { return collision_detection; }
				void draw() override;
			};
		}
	}
}