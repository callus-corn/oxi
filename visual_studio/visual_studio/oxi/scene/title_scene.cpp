#include <algorithm>
#include "title_scene.hpp"
#include "i_game_object.hpp"
#include "Dxlib.h"

void oxi::scene::TitleScene::run()
{
	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) {game_object->run(); });

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
	
	std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<IGameObject> game_object) {game_object->draw(); });

	ScreenFlip();
}
