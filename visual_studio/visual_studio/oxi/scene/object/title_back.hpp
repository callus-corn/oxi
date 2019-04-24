#pragma once

#include "../i_gate.hpp"
#include <string>
#include <memory>

namespace oxi 
{
	class IController;

	namespace scene
	{
		class IPosition;

		namespace object
		{
			class TitleBack :public IGate
			{
			private:
				int sound_;
				int image_;
				int kind_;
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IController> controller_;
				std::string next_scene_name{};
			public:
				explicit TitleBack(std::shared_ptr<IPosition> position,std::shared_ptr<IController> controller);
				void run() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() { return kind_; }
				bool isDisposable() override { return false; }
				int getImage() { return image_; }
				bool isOpen() override;
				std::string getNextSceneName() override;
			};
		}
	}
}