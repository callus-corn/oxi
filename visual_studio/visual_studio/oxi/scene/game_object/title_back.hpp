#pragma once

#include "../i_game_object.hpp"
#include "i_game_object_observer.hpp"
#include "i_game_object_subject.hpp"
#include <string>

namespace oxi 
{
	namespace scene
	{
		namespace game_object
		{
			class TitleBack :public IGameObject, public IGameObjectObserver, public IGameObjectSubject
			{
			private:
				int hoge;
				int fuga;
			public:
				TitleBack(std::shared_ptr<ISceneObserver> constractor_scene_observer);
				void run() override {};
				void draw() override;
				void update(std::map<Key,Frame> input) override;
			};
		}
	}
}