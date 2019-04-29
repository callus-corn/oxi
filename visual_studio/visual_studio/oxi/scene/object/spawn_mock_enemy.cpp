#include "spawn_mock_enemy.hpp"
#include "object_kind.hpp"
#include "mock_enemy.hpp"
#include "position.hpp"

oxi::scene::object::SpawnMockEnemy::SpawnMockEnemy(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::spawn)
{
}

void oxi::scene::object::SpawnMockEnemy::run()
{
	frame_++;
	if (frame_ > 90)
	{
		creatable_ = true;
		frame_ = 0;
	}
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnMockEnemy::create()
{
	creatable_ = false;
	auto position = std::make_shared<Position>(position_->getX(),position_->getY(),position_->getLengthX(), position_->getLengthY());
	return std::make_shared<MockEnemy>(position);
}