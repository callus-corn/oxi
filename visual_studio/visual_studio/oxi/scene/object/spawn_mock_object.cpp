#include "spawn_mock_object.hpp"
#include "mock_object.hpp"
#include "object_kind.hpp"

oxi::scene::object::SpawnMockObject::SpawnMockObject(std::shared_ptr<IPosition> position, std::shared_ptr<IController> controller)
	:position_(position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::back_ground)
{
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockObject::create()
{
	creatable_ = false;
	return std::make_shared<MockObject>(position_,controller_);
}