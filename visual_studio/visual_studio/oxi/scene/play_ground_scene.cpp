#include "play_ground_scene.hpp"
#include <algorithm>
#include "Dxlib.h"
#include "i_object.hpp"
#include "i_spawn.hpp"
#include "i_gate.hpp"

oxi::scene::PlayGroundScene::PlayGroundScene(std::vector<std::shared_ptr<ISpawn>> spawns, std::vector<std::shared_ptr<IGate>> gates)
	:spawns_(spawns),
	gates_(gates)
{
	for (auto spawn : spawns)
	{
		objects_.push_back(spawn);
	}
	for (auto gate : gates)
	{
		objects_.push_back(gate);
	}
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

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	for (auto object : objects_)
	{
		object->draw();
	}
	for (auto gate : gates_)
	{
		gate->draw();
	}

	ScreenFlip();

	for (auto gate : gates_) 
	{
		if (gate->isOpen()) 
		{
			next_scene_name = gate->getNextSceneName();
		}
	}
}