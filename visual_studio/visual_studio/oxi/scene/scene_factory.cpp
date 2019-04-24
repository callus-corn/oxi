#include "scene_factory.hpp"
#include "scene_const.hpp"
#include "i_spawn_factory.hpp"
#include "i_gate_factory.hpp"
#include "i_camera_factory.hpp"
#include "title_scene.hpp"
#include "play_ground_scene.hpp"

std::shared_ptr<oxi::IScene> oxi::scene::SceneFactory::create(std::string scene_name)
{
	std::vector<std::shared_ptr<ISpawn>> spawns{ spawn_factory_->create(scene_name) };
	std::vector<std::shared_ptr<IGate>> gates{ gate_factory_->create(scene_name) };
	std::shared_ptr<ICamera> camera = camera_factory_->create(scene_name);

	if (scene_name == oxi::scene::SceneConst::title_scene_name) 
	{
		auto scene = std::make_shared<TitleScene>(gates,camera);
		return scene;
	}
	else if (scene_name == oxi::scene::SceneConst::debug_scene_name)
	{
		auto scene = std::make_shared<PlayGroundScene>(spawns,gates,camera);
		return scene;
	}
	else
	{
		auto scene = std::make_shared<TitleScene>(gates,camera);
		return scene;
	}
}
