#include "title_scene.hpp"
#include "sequence.hpp"
#include "Dxlib.h"


void oxi::TitleScene::calculate()
{
}

void oxi::TitleScene::draw()
{
	sequence->changePlayGroundScene();
}