#include "game.hpp"
#include "DxLib.h"
#include "game_const.hpp"
#include "i_scene_factory.hpp"
#include "i_scene.hpp"
#include "i_controller.hpp"
#include "scene/scene_const.hpp"

oxi::Game::Game(std::shared_ptr<ISceneFactory> scene_factory, std::shared_ptr<IController> controller)
	:scene_factory_(scene_factory),
	controller_(controller)
{
}

void oxi::Game::start()
{
	SetOutApplicationLogValidFlag(FALSE);
	if (DxLib_Init() == -1) { return; }
	SetMainWindowText(oxi::GameConst::title_name);
	ChangeWindowMode(TRUE);
	SetGraphMode(oxi::GameConst::window_x, oxi::GameConst::window_y, oxi::GameConst::color_depth);
	SetWindowSizeChangeEnableFlag(FALSE);

	std::shared_ptr<IScene> scene = scene_factory_->create(oxi::scene::SceneConst::title_scene_name);

	while (ProcessMessage() == 0) 
	{
		controller_->update();
		scene->run();
		if (scene->isStopped())
		{
			scene = scene_factory_->create(scene->getNextSceneName());
		}
	}

	DxLib_End();
}