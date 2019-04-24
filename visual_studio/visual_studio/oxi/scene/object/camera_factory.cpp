#include "camera_factory.hpp"
#include "../../game_const.hpp"
#include "../scene_const.hpp"
#include "camera.hpp"
#include "position.hpp"
#include "object_const.hpp"

std::shared_ptr<oxi::scene::ICamera> oxi::scene::object::CameraFactory::create(std::string scene_name)
{
	auto position = std::make_shared<Position>(0, 0, 0, 0);
	auto right = std::make_shared<Position>(oxi::GameConst::window_x / 2, 0, oxi::GameConst::window_x / 2, oxi::GameConst::window_y);
	auto left = std::make_shared<Position>(-oxi::GameConst::window_x, 0, oxi::GameConst::window_x * 9 / 8, oxi::GameConst::window_y);
	auto camera = std::make_shared<Camera>(position, right, left);
	return camera;
}
