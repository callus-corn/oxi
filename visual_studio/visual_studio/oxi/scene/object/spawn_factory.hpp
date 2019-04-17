#pragma once

#include "../i_spawn_factory.hpp"

namespace oxi
{
	class IController;

	namespace scene 
	{
		namespace object
		{
			class SpawnFactory :public ISpawnFactory
			{
			private:
				std::shared_ptr<IController> controller_;
			public:
				explicit SpawnFactory(std::shared_ptr<IController> controller):controller_(controller) {}
				std::vector<std::shared_ptr<ISpawn>> create(std::string scene_name) override;
			};
		}
	}
}