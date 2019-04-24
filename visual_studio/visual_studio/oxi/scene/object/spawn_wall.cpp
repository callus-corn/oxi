#include "spawn_wall.hpp"
#include "object_kind.hpp"
#include "wall.hpp"

oxi::scene::object::SpawnWall::SpawnWall(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::spawn)
{
}

std::shared_ptr<oxi::scene::IObject> oxi::scene::object::SpawnWall::create()
{
	creatable_ = false;
	return std::make_shared<Wall>(position_);
}
