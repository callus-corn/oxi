#include "mock_ground.hpp"
#include "Dxlib.h"
#include <memory>

namespace
{
	static const Kind kind = oxi::scene::game_object::ObjectClassification::ground;
	static const int collision_detection_x_length = 1280;
	static const int collision_detection_y_length = 90;
	static const oxi::scene::game_object::Position initial_position(0, 720-90);
}

oxi::scene::game_object::MockGround::MockGround()
	:collision_detection(std::make_shared<CollisionDetection>(kind,collision_detection_x_length,collision_detection_y_length,initial_position))
{
	image = LoadGraph("resources/none_ground.png");
}

void oxi::scene::game_object::MockGround::draw()
{
	DrawGraph(collision_detection->getX(), collision_detection->getY(), image, 0);
}
