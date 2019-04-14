#pragma once

#include "collision_detection.hpp"
#include "../i_game_object.hpp"
#include <vector>

namespace oxi
{
	namespace scene 
	{
		namespace game_object
		{
			class Bullet : public IGameObject
			{
			private:
				Image image;
				std::shared_ptr<CollisionDetection> collision_detection;
				std::vector<Kind> collision_kinds{};
			public:
				Bullet(std::shared_ptr<CollisionDetection> constractor_collision_detection);
				void run() override;
				std::shared_ptr<ICollisionDetection> getCollisionDetection() { return collision_detection; }
				void draw() override;
				bool isDisposable() override { return false; }
			};
		}
	}
}