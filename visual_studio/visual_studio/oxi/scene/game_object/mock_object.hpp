#pragma once

#include <memory>
#include "../../i_controllable.hpp"
#include "../i_game_object.hpp"
#include "../i_scene_observer.hpp"
#include "i_game_object_subject.hpp"

namespace oxi
{
	namespace scene 
	{
		namespace game_object
		{
			class MockObject :public IGameObject,public IControllable,public IGameObjectSubject
			{
			private:
				int hoge;
				int fuga;
			public:
				MockObject();
				void setSceneObserver(std::shared_ptr<ISceneObserver> setted_scene_observer) override { scene_observer = setted_scene_observer; }
				void run() override {};
				void draw() override;
				void update(std::map<Key, Frame> input) override;
			};
		}
	}
}