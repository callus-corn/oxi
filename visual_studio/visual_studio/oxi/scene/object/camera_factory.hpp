#pragma once

#include "../i_camera_factory.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class CameraFactory :public ICameraFactory
			{
			public:
				std::shared_ptr<ICamera> create(std::string scene_name) override;
			};
		}
	}
}