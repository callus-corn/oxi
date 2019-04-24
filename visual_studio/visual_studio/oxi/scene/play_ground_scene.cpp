#include "play_ground_scene.hpp"
#include <algorithm>
#include "Dxlib.h"
#include "i_object.hpp"
#include "i_spawn.hpp"
#include "i_gate.hpp"
#include "i_camera.hpp"

oxi::scene::PlayGroundScene::PlayGroundScene(std::vector<std::shared_ptr<ISpawn>> spawns, std::vector<std::shared_ptr<IGate>> gates, std::shared_ptr<ICamera> camera)
	:spawns_(spawns),
	gates_(gates),
	camera_(camera)
{
	for (auto spawn : spawns)
	{
		objects_.push_back(spawn);
	}
	for (auto gate : gates)
	{
		objects_.push_back(gate);
	}
	objects_.push_back(camera);
}

void oxi::scene::PlayGroundScene::run()
{
	for (auto spawn : spawns_)
	{
		if (spawn->isCreatable())
		{
			objects_.push_back(spawn->create());
		}
	}

	for (auto object : objects_)
	{
		object->run();
	}

	for (auto object : objects_)
	{
		for (auto obstacle : objects_)
		{
			object->collisionStore(obstacle->getPosition(),obstacle->getKind());
		}
	}
	for (auto object : objects_)
	{
		object->collision();
	}

	auto new_end = std::remove_if(objects_.begin(), objects_.end(), [](auto object) {return object->isDisposable();});
	objects_.erase(new_end, objects_.end());


	camera_->ready();
	for (auto object : objects_)
	{
		camera_->render(object->getPosition(),object->getImage(),object->getKind());
	}
	for (auto gate : gates_)
	{
		camera_->render(gate->getPosition(),gate->getImage(),gate->getKind());
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