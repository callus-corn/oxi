#include "title_scene.hpp"
#include "Dxlib.h"
#include "i_object.hpp"
#include "i_gate.hpp"
#include "i_camera.hpp"

oxi::scene::TitleScene::TitleScene(std::vector<std::shared_ptr<IGate>> gates, std::shared_ptr<ICamera> camera)
	:gates_(gates),
	camera_(camera)
{
	for (auto gate : gates)
	{
		objects_.push_back(gate);
	}
	objects_.push_back(camera);
}

void oxi::scene::TitleScene::run()
{
	for (auto object : objects_)
	{
		object->run();
	}

	camera_->ready();
	for (auto object : objects_)
	{
		camera_->render(object->getPosition(), object->getImage(), object->getKind());
	}
	camera_->refresh();

	for (auto gate : gates_)
	{
		if (gate->isOpen())
		{
			next_scene_name = gate->getNextSceneName();
		}
	}
}
