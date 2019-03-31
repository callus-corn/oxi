#include <algorithm>
#include "play_ground_scene.hpp"
#include "Dxlib.h"

void oxi::scene::PlayGroundScene::run()
{
	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) {game_object->run(); });

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) {game_object->draw(); });

	ScreenFlip();
}
