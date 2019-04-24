#include "spawn_mock_enemy.hpp"
#include "object_kind.hpp"
#include "mock_enemy.hpp"

oxi::scene::object::SpawnMockEnemy::SpawnMockEnemy(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::spawn)
{
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockEnemy::create()
{
	creatable_ = false;
	return std::make_shared<MockEnemy>(position_);
}