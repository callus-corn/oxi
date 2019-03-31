#pragma once

#include <string>

namespace oxi
{
	namespace scene 
	{
		class ISceneObserver
		{
		public:
			virtual void update(std::string next_scene_name) {}
		};
	}
}