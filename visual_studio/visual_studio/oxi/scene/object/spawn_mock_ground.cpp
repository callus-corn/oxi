#include "spawn_mock_ground.hpp"
#include "mock_ground.hpp"
#include "object_kind.hpp"

oxi::scene::object::SpawnMockGround::SpawnMockGround(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::spawn)
{
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockGround::create()
{
	creatable_ = false;
	return std::make_shared<MockGround>(position_);
}
