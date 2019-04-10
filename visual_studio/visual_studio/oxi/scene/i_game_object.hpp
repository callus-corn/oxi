#pragma once

#include <memory>
#include "i_collision_detection.hpp"

using Image = int;
using Sound = int;

namespace oxi
{
	namespace scene 
	{
		class IGameObject
		{
		public:
			virtual ~IGameObject() {}
			virtual void run() {}
			virtual void collisionDetect(std::shared_ptr<ICollisionDetection> obstacle_collision_detection) {}
			virtual void collision() {}
			virtual std::shared_ptr<ICollisionDetection> getCollisionDetection() = 0;
			virtual void draw() {}
		};
	}
}