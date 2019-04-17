#pragma once

#include <vector>
#include <memory>
#include "../i_scene.hpp"

namespace oxi 
{
	namespace scene 
	{
		class ISpawn;
		class IObject;
		class IGate;

		class PlayGroundScene :public IScene
		{
		private:
			std::vector<std::shared_ptr<ISpawn>> spawns_;
			std::vector<std::shared_ptr<IGate>> gates_;
			std::vector<std::shared_ptr<IObject>> objects_{};
			std::string next_scene_name{};
		public:
			explicit PlayGroundScene(std::vector<std::shared_ptr<ISpawn>> spawns, std::vector<std::shared_ptr<IGate>> gates);
			void run() override;
			bool isStopped() override { return !next_scene_name.empty(); }
			std::string getNextSceneName() override { return next_scene_name; }
		};
	}
}