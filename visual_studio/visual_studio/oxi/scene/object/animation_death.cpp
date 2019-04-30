#include "animation_death.hpp"
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "object_kind.hpp"
#include "object_const.hpp"
#include "animation_resources.hpp"
#include "position.hpp"
#include "corpse.hpp"

oxi::scene::object::AnimationDeath::AnimationDeath(std::shared_ptr<IPosition> object_position, std::shared_ptr<IController> controller,int direction)
	:position_(std::make_shared<Position>(object_position->getX(), object_position->getY(), object_position->getLengthX(), object_position->getLengthY())),
	object_position_(object_position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::animation),
	direction_(direction)
{
}

void oxi::scene::object::AnimationDeath::run()
{
	position_->moveTo(object_position_->getX(), object_position_->getY());
	auto input = controller_->getInput();
	if (!active_ && input.at(KEY_INPUT_R))
	{
		active_ = true;
	}
}

void oxi::scene::object::AnimationDeath::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::AnimationDeath::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::enemy && active_)
		{
			creatable_ = true;
		}
	}
	position_->resetCollisions();
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::AnimationDeath::create()
{
	active_ = false;
	creatable_ = false;
	auto y = position_->getY();
	if (direction_ == oxi::scene::object::ObjectConst::down)
	{
		y = position_->getY() + oxi::scene::object::ObjectConst::unit_y;
	}
	auto position = std::make_shared<Position>(position_->getX(), y,0,0);
	auto image = -1;
	auto move = 0;
	if (direction_ == oxi::scene::object::ObjectConst::up)
	{
		move = -oxi::scene::object::ObjectConst::move_speed;
		image = LoadGraph(oxi::scene::object::AnimationResources::player_up);
	}
	if (direction_ == oxi::scene::object::ObjectConst::down)
	{
		move = oxi::scene::object::ObjectConst::move_speed;
		image = LoadGraph(oxi::scene::object::AnimationResources::player_down);
	}
	auto corpse = std::make_shared<Corpse>(position, move, image);
	return corpse;
}
