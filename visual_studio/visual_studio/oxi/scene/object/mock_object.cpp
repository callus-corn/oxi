#include "mock_object.hpp"
#include <memory>
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "../../game_const.hpp"
#include "../i_position.hpp"
#include "object_kind.hpp"
#include "image_resources.hpp"
#include "object_const.hpp"

oxi::scene::object::MockObject::MockObject(std::shared_ptr<oxi::scene::IPosition> position, std::shared_ptr<oxi::IController> controller)
	:position_(position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::player)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_object);
}

void oxi::scene::object::MockObject::run()
{
	auto input = controller_->getInput();

	position_->addY(oxi::scene::object::ObjectConst::gravity);

	if (input.at(KEY_INPUT_RIGHT) > 0)
	{
		position_->addX(oxi::scene::object::ObjectConst::move_speed);
	}
	if (input.at(KEY_INPUT_LEFT) > 0)
	{
		position_->addX(-oxi::scene::object::ObjectConst::move_speed);
	}
	if (input.at(KEY_INPUT_UP) == 1 )
	{
		frame_++;
	}

	if (frame_ > 0)
	{
		auto delta = -(oxi::scene::object::ObjectConst::jump_verocity-frame_);
		position_->addY(delta);
		frame_++;
	}
}

void oxi::scene::object::MockObject::collisionStore(std::shared_ptr<IPosition> position,int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::MockObject::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::ground) 
		{
			position_->moveTo(position_->getX(), oxi::GameConst::window_y - oxi::scene::object::ObjectConst::unit_y * 4);
			frame_ = 0;
		}
	}
	position_->resetCollisions();
}