#include "wall.hpp"
#include "object_kind.hpp"

oxi::scene::object::Wall::Wall(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::wall)
{
}
