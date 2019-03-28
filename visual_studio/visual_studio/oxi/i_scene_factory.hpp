#pragma once

#include <string>

namespace oxi 
{
	class IScene;

	class ISceneFactory 
	{
	public:
		virtual std::shared_ptr<IScene> create(std::string scene_name)=0;
		virtual ~ISceneFactory() {}
	};
}