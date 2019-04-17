#include "mock_ground.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "object_kind.hpp"
#include "image_resources.hpp"

oxi::scene::object::MockGround::MockGround(std::shared_ptr<oxi::scene::IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::ground)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_ground);
}

void oxi::scene::object::MockGround::draw()
{
	DrawGraph(position_->getX(), position_->getY(), image_, 0);
}
