#pragma once

#include "../i_scene_factory.hpp"

namespace oxi 
{
	namespace scene 
	{
		class ISpawnFactory;
		class IGateFactory;

		class SceneFactory :public ISceneFactory
		{
		private:
			std::shared_ptr<ISpawnFactory> spawn_factory_;
			std::shared_ptr<IGateFactory> gate_factory_;
		public:
			explicit SceneFactory(std::shared_ptr<ISpawnFactory> spawn_factory, std::shared_ptr<IGateFactory> gate_factory)
				:spawn_factory_(spawn_factory),
				gate_factory_(gate_factory){}
			std::shared_ptr<IScene> create(std::string scene_name) override;
		};
	}
}