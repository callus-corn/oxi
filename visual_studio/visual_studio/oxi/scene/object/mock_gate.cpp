#include "mock_gate.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "../scene_const.hpp"
#include "object_kind.hpp"
#include "image_resources.hpp"

oxi::scene::object::MockGate::MockGate(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::gate)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_gate);
}

void oxi::scene::object::MockGate::collisionStore(std::shared_ptr<IPosition> position, int kind)
{
	if (position_->isCollision(position))
	{
		position_->addCollision(kind);
	}
}

void oxi::scene::object::MockGate::collision()
{
	auto collisions = position_->getCollisions();
	for (auto collision : collisions)
	{
		if (collision == oxi::scene::object::ObjectKind::player)
		{
			next_scene_name_ = oxi::scene::SceneConst::title_scene_name;
		}
	}
	position_->resetCollisions();
}