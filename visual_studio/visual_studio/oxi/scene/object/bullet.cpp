#include "bullet.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "object_kind.hpp"
#include "image_resources.hpp"
#include "object_const.hpp"

oxi::scene::object::Bullet::Bullet(std::shared_ptr<IPosition> position,int move_speed)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::bullet),
	move_speed_(move_speed)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_bullet);
}

void oxi::scene::object::Bullet::run()
{
	frame_++;
	position_->addX(move_speed_*2);
	if (frame_ > 60)
	{
		disposable_ = true;
	}
}

void oxi::scene::object::Bullet::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::Bullet::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::enemy)
		{
			disposable_ = true;
		}
	}
	position_->resetCollisions();
}

void oxi::scene::object::Bullet::draw()
{
	DrawGraph(position_->getX(), position_->getY(), image_, 0);
}
