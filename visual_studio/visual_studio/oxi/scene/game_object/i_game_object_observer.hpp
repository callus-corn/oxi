#pragma once

#include <map>

using Key = int;
using Frame = int;

namespace oxi
{
	namespace scene
	{
		namespace game_object
		{
			class IGameObjectObserver
			{
			public:
				virtual void update(std::map<Key,Frame> input) {}
			};
		}
	}
}