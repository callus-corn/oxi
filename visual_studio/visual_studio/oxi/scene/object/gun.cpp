#include "gun.hpp"
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "sound_resources.hpp"
#include "bullet.hpp"
#include "position.hpp"
#include "object_const.hpp"
#include "object_kind.hpp"

namespace
{
	int sound_;
	int move_speed_{ oxi::scene::object::ObjectConst::move_speed };
}

oxi::scene::object::Gun::Gun(std::shared_ptr<IPosition> object_position,std::shared_ptr<IController> controller)
	:position_(std::make_shared<Position>(object_position->getX(), object_position->getY(), object_position->getLengthX(), object_position->getLengthY())),
	object_position_(object_position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::gun)
{
	sound_ = LoadSoundMem(oxi::scene::object::SoundResources::shot);
}

void oxi::scene::object::Gun::run()
{
	position_->moveTo(object_position_->getX(),object_position_->getY());
	auto input = controller_->getInput();
	if (input.at(KEY_INPUT_LEFT))
	{
		move_speed_ = -oxi::scene::object::ObjectConst::move_speed;
	}
	else if (input.at(KEY_INPUT_RIGHT))
	{
		move_speed_ = oxi::scene::object::ObjectConst::move_speed;
	}
	if (!active_ && input.at(KEY_INPUT_R))
	{
		active_ = true;
	}
}

void oxi::scene::object::Gun::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::Gun::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::enemy)
		{
			active_ = false;
		}
	}
	position_->resetCollisions();
}

bool oxi::scene::object::Gun::isCreatable()
{
	auto input = controller_->getInput();
	return input.at(KEY_INPUT_Z) == 1 && active_;
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::Gun::create()
{
	auto sign = move_speed_ >= 0 ? 1:-1;
	auto position = std::make_shared<Position>(position_->getX() + sign*oxi::scene::object::ObjectConst::unit_x / 2, position_->getY() + oxi::scene::object::ObjectConst::unit_y / 2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y);
	PlaySoundMem(sound_,DX_PLAYTYPE_BACK);
	return std::make_shared<Bullet>(position,move_speed_);
}
