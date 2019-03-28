#pragma once

#include <string>

namespace oxi
{
	class IGameObserver 
	{
	public:
		virtual void update(std::string next_scene_name) {}
		virtual ~IGameObserver() {}
	};
}