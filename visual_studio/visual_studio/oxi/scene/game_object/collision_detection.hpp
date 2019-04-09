#pragma once

#include "../i_collision_detection.hpp"
#include "position.hpp"
#include "object_classification.hpp"

namespace oxi
{
	namespace scene
	{
		namespace game_object
		{
			class CollisionDetection :public ICollisionDetection
			{
			private:
				Position position;
			public:
				explicit CollisionDetection(Kind constracto_kind,Length constractor_x_length,Length constractor_y_length, Position constractor_position)
					:ICollisionDetection(constracto_kind,constractor_x_length,constractor_y_length),
					position(constractor_position){}
				void addX(X difference_x) { position.addX(difference_x); }
				void addY(Y difference_y) { position.addY(difference_y); }
				void moveTo(X destination_x, Y destination_y) { position.moveTo(destination_x, destination_y); }
				X getX() override { return position.getX(); }
				Y getY() override { return position.getY(); }
			};
		}
	}
}