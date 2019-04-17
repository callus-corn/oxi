#include "title_back.hpp"
#include "Dxlib.h"
#include "../../i_controller.hpp"
#include "../i_position.hpp"
#include "../scene_const.hpp"
#include "image_resources.hpp"
#include "sound_resources.hpp"
#include "object_kind.hpp"

oxi::scene::object::TitleBack::TitleBack(std::shared_ptr<oxi::scene::IPosition> position,std::shared_ptr<oxi::IController> controller)
	:position_(position),
	controller_(controller),
	kind_(oxi::scene::object::ObjectKind::back_ground)
{
	image_ = LoadGraph(oxi::scene::object::ImageResources::title_back);
	sound_ = LoadSoundMem(oxi::scene::object::SoundResources::title_back);
	PlaySoundMem(sound_, DX_PLAYTYPE_LOOP);
}

void oxi::scene::object::TitleBack::run()
{
	auto input = controller_->getInput();
	if (input.at(KEY_INPUT_Z) > 0)
	{
		StopSoundMem(sound_);
		next_scene_name = oxi::scene::SceneConst::debug_scene_name;
	}
}

void oxi::scene::object::TitleBack::draw()
{
	DrawGraph(position_->getX(), position_->getY(),image_,0);
}

bool oxi::scene::object::TitleBack::isOpen()
{
	return !next_scene_name.empty();
}

std::string oxi::scene::object::TitleBack::getNextSceneName()
{
	return next_scene_name;
}