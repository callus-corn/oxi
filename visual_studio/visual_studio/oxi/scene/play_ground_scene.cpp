#include <algorithm>
#include "play_ground_scene.hpp"
#include "Dxlib.h"

void oxi::scene::PlayGroundScene::run()
{
	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) 
	{
		game_object->run(); 
	});

	for(auto collisionable : game_objects)
	{
		for (auto obstacle : game_objects) 
		{
			collisionable->collisionDetect(obstacle->getCollisionDetection());
		}
	}
	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) 
	{
		game_object->collision();
	});

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object)
	{
		game_object->draw(); 
	});

	ScreenFlip();
}
