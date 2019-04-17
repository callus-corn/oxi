#include "spawn_mock_background.hpp"
#include "mock_background.hpp"
#include "object_kind.hpp"

oxi::scene::object::SpawnMockBackGround::SpawnMockBackGround(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::back_ground)
{
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockBackGround::create()
{
	creatable_ = false;
	return std::make_shared<MockBackGround>(position_);
}
