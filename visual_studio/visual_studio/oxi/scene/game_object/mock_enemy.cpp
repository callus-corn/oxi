#include "mock_enemy.hpp"
#include "Dxlib.h"

namespace
{
	static const Kind kind = oxi::scene::game_object::ObjectClassification::enemy;
	static const int collision_detection_x_length = 100;
	static const int collision_detection_y_length = 100;
	static const int initial_x = 3 * (1280 / 4) - 100;
	static const int initial_y = 720 / 2 - 100;
	static const oxi::scene::game_object::Position initial_position(initial_x,initial_y);
}

namespace
{
	static const int gravity = 10;
}

oxi::scene::game_object::MockEnemy::MockEnemy()
	:collision_detection(std::make_shared<CollisionDetection>(kind, collision_detection_x_length, collision_detection_y_length, initial_position))
{
	image = LoadGraph("resources/none_enemy.png");
}

void oxi::scene::game_object::MockEnemy::run()
{
	frame++;
	collision_detection->moveTo(initial_x + int(100*sin(double(frame)/10)),collision_detection->getY());
	collision_detection->addY(gravity);
}

void oxi::scene::game_object::MockEnemy::collisionDetect(std::shared_ptr<ICollisionDetection> obstacle_collision_detection)
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

void oxi::scene::game_object::MockEnemy::collision()
{
	for (auto obstacle_kind : collision_kinds)
	{
		if (obstacle_kind == oxi::scene::game_object::ObjectClassification::ground)
		{
			collision_detection->addY(-gravity);
		}
		if (obstacle_kind == oxi::scene::game_object::ObjectClassification::bullet)
		{
			disposable = true;
		}
	}
	std::vector<Kind> reset{};
	collision_kinds = reset;
}

void oxi::scene::game_object::MockEnemy::draw()
{
	DrawGraph(collision_detection->getX(), collision_detection->getY(), image, 0);
}