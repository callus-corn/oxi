#include "title_scene.hpp"
#include "Dxlib.h"
#include "i_object.hpp"
#include "i_gate.hpp"

oxi::scene::TitleScene::TitleScene(std::vector<std::shared_ptr<IGate>> gates)
	:gates_(gates)
{
	for (auto gate : gates)
	{
		objects_.push_back(gate);
	}
}

void oxi::scene::TitleScene::run()
{
	for (auto object : objects_)
	{
		object->run();
	}

	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
	
	for (auto object : objects_)
	{
		object->draw();
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
