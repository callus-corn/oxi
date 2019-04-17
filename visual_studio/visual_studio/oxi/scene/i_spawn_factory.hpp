#pragma once

#include <vector>
#include <memory>
#include <string>

namespace oxi
{
	namespace scene
	{
		class ISpawn;

		class ISpawnFactory
		{
		public:
			virtual ~ISpawnFactory() {}
			virtual std::vector<std::shared_ptr<ISpawn>> create(std::string scene_name) = 0;
		};
	}
}