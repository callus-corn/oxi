#include "spawn_bullet.hpp"
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "bullet.hpp"
#include "position.hpp"
#include "object_const.hpp"
#include "object_kind.hpp"

oxi::scene::object::SpawnBullet::SpawnBullet(std::shared_ptr<IPosition> position,std::shared_ptr<IController> controller)
	:position_(position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::spawn),
	move_speed_(oxi::scene::object::ObjectConst::move_speed)
{
}

void oxi::scene::object::SpawnBullet::run()
{
	auto input = controller_->getInput();
	if (input.at(KEY_INPUT_LEFT))
	{
		move_speed_ = -oxi::scene::object::ObjectConst::move_speed;
	}
	else if (input.at(KEY_INPUT_RIGHT))
	{
		move_speed_ = oxi::scene::object::ObjectConst::move_speed;
	}
}

bool oxi::scene::object::SpawnBullet::isCreatable()
{
	auto input = controller_->getInput();
	return input.at(KEY_INPUT_Z) == 1;
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnBullet::create()
{
	auto position = std::make_shared<Position>(position_->getX() + oxi::scene::object::ObjectConst::unit_x / 2, position_->getY() + oxi::scene::object::ObjectConst::unit_y / 2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y);
	return std::make_shared<Bullet>(position,move_speed_);
}
