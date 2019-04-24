#include "camera.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "object_kind.hpp"
#include "object_const.hpp"

oxi::scene::object::Camera::Camera(std::shared_ptr<IPosition> position, std::shared_ptr<IPosition> right, std::shared_ptr<IPosition> left)
	:position_(position),
	right_(right),
	left_(left),
	kind_(oxi::scene::object::ObjectKind::camera)
{
}

void oxi::scene::object::Camera::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (right_->isCollision(position))
	{
		right_->addCollision(kind);
	}
	if (left_->isCollision(position))
	{
		left_->addCollision(kind);
	}
}

void oxi::scene::object::Camera::collision()
{
	auto right_collisions = right_->getCollisions();
	for (auto collision : right_collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::player)
		{
			position_->addX(oxi::scene::object::ObjectConst::move_speed);
			right_->addX(oxi::scene::object::ObjectConst::move_speed);
			left_->addX(oxi::scene::object::ObjectConst::move_speed);
		}
	}
	right_->resetCollisions();

	auto left_collisions = left_->getCollisions();
	for (auto collision : left_collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::player)
		{
			position_->addX(-oxi::scene::object::ObjectConst::move_speed);
			right_->addX(-oxi::scene::object::ObjectConst::move_speed);
			left_->addX(-oxi::scene::object::ObjectConst::move_speed);
		}
	}
	left_->resetCollisions();
}

void oxi::scene::object::Camera::ready()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
}

void oxi::scene::object::Camera::render(std::shared_ptr<IPosition> position, int image, int kind)
{
	if (image == -1) { return; }
	DrawGraph(position->getX() - position_->getX(), position->getY() - position_->getY(), image, 0);
}

void oxi::scene::object::Camera::refresh()
{
	ScreenFlip();
}
