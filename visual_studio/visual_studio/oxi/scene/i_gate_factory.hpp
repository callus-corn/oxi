#pragma once

#include <vector>
#include <memory>
#include <string>

namespace oxi
{
	namespace scene
	{
		class IGate;

		class IGateFactory
		{
		public:
			virtual ~IGateFactory() {}
			virtual std::vector<std::shared_ptr<IGate>> create(std::string scene_name) = 0;
		};
	}
}