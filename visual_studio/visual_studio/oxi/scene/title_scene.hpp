#pragma once

#include <vector>
#include <memory>
#include "../i_scene.hpp"

namespace oxi
{
	namespace scene
	{
		class IObject;
		class IGate;
		class ICamera;

		class TitleScene :public IScene
		{
		private:
			std::vector<std::shared_ptr<IGate>> gates_;
			std::shared_ptr<ICamera> camera_;
			std::vector<std::shared_ptr<IObject>> objects_;
			std::string next_scene_name{};
		public:
			explicit TitleScene(std::vector<std::shared_ptr<IGate>> gates, std::shared_ptr<ICamera> camera);
			void run() override;
			bool isStopped() override { return !next_scene_name.empty(); }
			std::string getNextSceneName() override { return next_scene_name; }
		};
	}
}