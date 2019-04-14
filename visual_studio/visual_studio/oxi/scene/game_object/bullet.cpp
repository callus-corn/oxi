#include "bullet.hpp"
#include "position.hpp"
#include "object_classification.hpp"
#include "Dxlib.h"

oxi::scene::game_object::Bullet::Bullet(std::shared_ptr<CollisionDetection> constractor_collision_detection)
{
	Position position(constractor_collision_detection->getX(), constractor_collision_detection->getY()+50);
	collision_detection = std::make_shared<CollisionDetection>(oxi::scene::game_object::ObjectClassification::bullet, constractor_collision_detection->getXLength(), constractor_collision_detection->getYLength(), position);
	image = LoadGraph("resources/none_bullet.png");
}

void oxi::scene::game_object::Bullet::run()
{
	collision_detection->addX(10);
}

void oxi::scene::game_object::Bullet::draw()
{
	DrawGraph(collision_detection->getX(), collision_detection->getY(), image, 0);
}
