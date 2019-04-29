#include "spawn_mock_object.hpp"
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "mock_object.hpp"
#include "object_kind.hpp"
#include "position.hpp"

oxi::scene::object::SpawnMockObject::SpawnMockObject(std::shared_ptr<IPosition> player_position, std::shared_ptr<IController> controller)
	:position_(std::make_shared<Position>(player_position->getX(), player_position->getY(),player_position->getLengthX(),player_position->getLengthY())),
	player_position_(player_position),
	controller_(controller),
	player_(std::make_shared<MockObject>(player_position,controller)),
	kind_(oxi::scene::object::ObjectKind::spawn)
{
}

bool oxi::scene::object::SpawnMockObject::isCreatable()
{
	auto input = controller_->getInput();
	return (input.at(KEY_INPUT_R) == 1 && player_->isDisposable()) || creatable_;
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockObject::create()
{
	creatable_ = false;
	if (player_->isDisposable()) 
	{
		player_position_->moveTo(position_->getX(), position_->getY());
		player_ = std::make_shared<MockObject>(player_position_, controller_);
	}
	return player_;
}