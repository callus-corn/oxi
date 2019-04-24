#include "mock_background.hpp"
#include "Dxlib.h"
#include "../i_position.hpp"
#include "object_kind.hpp"
#include "image_resources.hpp"

oxi::scene::object::MockBackGround::MockBackGround(std::shared_ptr<IPosition> position)
	:position_(position),
	kind_(oxi::scene::object::ObjectKind::ground)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::mock_background);
}