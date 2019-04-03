#pragma once

#include "../../i_controllable.hpp"
#include "../i_game_object.hpp"
#include "i_game_object_subject.hpp"
#include "position.hpp"
#include <string>

using Sound = int;
using Image = int;

namespace oxi 
{
	namespace scene
	{
		namespace game_object
		{
			class TitleBack :public IGameObject, public IControllable,public IGameObjectSubject
			{
			private:
				Sound sound;
				Image image;
				Position position;
			public:
				TitleBack();
				void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_observer) override { scene_observer = setted_scene_observer; }
				void run() override {};
				void draw() override;
				void update(std::map<Key,Frame> input) override;
			};
		}
	}
}