#include "mock_enemy.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "image_resources.hpp"
#include "object_kind.hpp"
#include "object_const.hpp"

oxi::scene::object::MockEnemy::MockEnemy(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::enemy)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_enemy);
}

void oxi::scene::object::MockEnemy::run()
{
	frame_++;
	int ux = oxi::scene::object::ObjectConst::unit_x;
	int old_frame = frame_ - 1;
	double t_old = 3.14 * double(old_frame) / 30;
	double t = 3.14 * double(frame_) / 30;
	int delta = int(ux*(sin(t) - sin(t_old)));
	position_->addX(delta);
	position_->addY(oxi::scene::object::ObjectConst::gravity);
}

void oxi::scene::object::MockEnemy::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::MockEnemy::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::ground)
		{
			position_->addY(-oxi::scene::object::ObjectConst::gravity);
		}
		if (collision == oxi::scene::object::ObjectKind::bullet)
		{
			disposable_ = true;
		}
	}
	position_->resetCollisions();
}