#include "corpse.hpp"
#include "object_kind.hpp"
#include "position.hpp"

oxi::scene::object::Corpse::Corpse(std::shared_ptr<IPosition> position, int move_speed, int image)
	:position_(position),
	move_speed_(move_speed),
	image_(image),
	kind_(oxi::scene::object::ObjectKind::corpse)
{
}

void oxi::scene::object::Corpse::run()
{
	position_->addY(move_speed_);
	frame++;
	if (frame > 60)
	{
		disposable_ = true;
	}
}
