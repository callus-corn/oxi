#pragma once

#include "collision_detection.hpp"
#include "../i_game_object.hpp"

namespace oxi
{
	namespace scene
	{
		namespace game_object
		{
			class MockGround :public IGameObject
			{
			private:
				Image image;
				std::shared_ptr<CollisionDetection> collision_detection;
			public:
				MockGround();
				std::shared_ptr<ICollisionDetection> getCollisionDetection() override { return collision_detection; }
				void draw() override;
			};
		}
	}
}