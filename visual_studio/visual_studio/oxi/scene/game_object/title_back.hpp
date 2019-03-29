#pragma once

#include "../i_game_object.hpp"
#include <string>

namespace oxi 
{
	namespace scene
	{
		namespace game_object
		{
			class TitleBack :public IGameObject 
			{
			private:
				int hoge;
				int fuga;
			public:
				explicit TitleBack();
				void run() override {};
				void draw() override;
			};
		}
	}
}