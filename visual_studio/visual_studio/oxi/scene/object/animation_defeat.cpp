#include "animation_defeat.hpp"
#include "Dxlib.h"
#include "object_kind.hpp"
#include "object_const.hpp"
#include "animation_resources.hpp"
#include "position.hpp"
#include "corpse.hpp"

oxi::scene::object::AnimationDefeat::AnimationDefeat(std::shared_ptr<std::vector<std::shared_ptr<IPosition>>> object_positions, int direction)
	:position_(std::make_shared<Position>(0,0,0,0)),
	object_positions_(object_positions),
	kind_(oxi::scene::object::ObjectKind::animation),
	direction_(direction)
{
}

void oxi::scene::object::AnimationDefeat::collision()
{
	for (auto position : *object_positions_)
	{
		auto collisions = position->getCollisions();
		for (auto collision : collisions)
		{
			if (collision == oxi::scene::object::ObjectKind::bullet)
			{
				position_ = std::make_shared<Position>(position->getX(), position->getY(), position->getLengthX(), position->getLengthY());
				creatable_ = true;
			}
		}
	}
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::AnimationDefeat::create()
{
	creatable_ = false;
	auto y = position_->getY();
	if (direction_ == oxi::scene::object::ObjectConst::down)
	{
		y = position_->getY() + oxi::scene::object::ObjectConst::unit_y;
	}
	auto position = std::make_shared<Position>(position_->getX(), y, 0, 0);
	auto move = 0;
	auto image = -1;
	if (direction_ == oxi::scene::object::ObjectConst::up)
	{
		move = -oxi::scene::object::ObjectConst::move_speed;
		image = LoadGraph(oxi::scene::object::AnimationResources::enemy_up);
	}
	if (direction_ == oxi::scene::object::ObjectConst::down)
	{
		move = oxi::scene::object::ObjectConst::move_speed;
		image = LoadGraph(oxi::scene::object::AnimationResources::enemy_down);
	}
	auto corpse = std::make_shared<Corpse>(position, move, image);
	return corpse;
}
