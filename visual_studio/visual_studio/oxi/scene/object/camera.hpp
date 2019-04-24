#pragma once

#include "../i_camera.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class Camera :public ICamera
			{
			private:
				int kind_;
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IPosition> right_;
				std::shared_ptr<IPosition> left_;
			public:
				explicit Camera(std::shared_ptr<IPosition> position, std::shared_ptr<IPosition> right, std::shared_ptr<IPosition> left);
				void collisionStore(std::shared_ptr<IPosition> position, int kind) override;
				void collision() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				void ready() override;
				void render(std::shared_ptr<IPosition> position, int image, int kind) override;
				void refresh() override;
			};
		}
	}
}