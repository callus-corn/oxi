#include "mock_object.hpp"
#include "Dxlib.h"
#include <memory>

namespace
{
	static const Kind kind = oxi::scene::game_object::ObjectClassification::player;
	static const int collision_detection_x_length = 100;
	static const int collision_detection_y_length = 100;
	static const oxi::scene::game_object::Position initial_position(1280/4 -100,720/2 -100);
}

namespace
{
	static const int gravity = 10;
	static const int move_speed = 10;
}

oxi::scene::game_object::MockObject::MockObject()
	:collision_detection(std::make_shared<CollisionDetection>(kind,collision_detection_x_length, collision_detection_y_length, initial_position))
{
	image = LoadGraph("resources/none.png");
}

void oxi::scene::game_object::MockObject::run()
{
	collision_detection->addY(gravity);
}

void oxi::scene::game_object::MockObject::collisionDetect(std::shared_ptr<ICollisionDetection> obstacle_collision_detection)
{
	bool horizontal_detect
		= collision_detection->getX() + collision_detection->getXLength() - obstacle_collision_detection->getX() > 0
		&& obstacle_collision_detection->getX() + obstacle_collision_detection->getXLength() - collision_detection->getX() > 0;
	bool vertical_detect
		= collision_detection->getY() + collision_detection->getYLength() - obstacle_collision_detection->getY() > 0
		&& obstacle_collision_detection->getY() + obstacle_collision_detection->getYLength() - collision_detection->getY() > 0;
	bool collision_detect = horizontal_detect && vertical_detect;

	if (collision_detect)
	{
		collision_kinds.push_back(obstacle_collision_detection->getKind());
	}
}

void oxi::scene::game_object::MockObject::collision()
{
	for (auto obstacle_kind : collision_kinds)
	{
		if (obstacle_kind == oxi::scene::game_object::ObjectClassification::ground) 
		{
			collision_detection->addY(-gravity);
		}
	}
	std::vector<Kind> reset{};
	collision_kinds = reset;
}

void oxi::scene::game_object::MockObject::draw()
{
	DrawGraph(collision_detection->getX(), collision_detection->getY(), image, 0);
}

void oxi::scene::game_object::MockObject::update(std::map<Key, Frame> input)
{
	if (input.at(KEY_INPUT_X) > 0)
	{
		scene_observer->update("title");
	}
	if (input.at(KEY_INPUT_RIGHT) > 0) 
	{
		collision_detection->addX(move_speed);
	}
	if (input.at(KEY_INPUT_LEFT) > 0)
	{
		collision_detection->addX(-move_speed);
	}
	if (input.at(KEY_INPUT_UP) > 0)
	{
		collision_detection->addY(-move_speed-gravity);
	}
}