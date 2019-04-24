#pragma once

#include <memory>
#include <string>

namespace oxi
{
	namespace scene
	{
		class ICamera;

		class ICameraFactory
		{
		public:
			virtual ~ICameraFactory() {}
			virtual std::shared_ptr<ICamera> create(std::string scene_name) = 0;
		};
	}
}