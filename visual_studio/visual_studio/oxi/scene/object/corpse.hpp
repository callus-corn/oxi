#pragma once

#include "../i_object.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class Corpse :public IObject
			{
			private:
				int image_;
				int move_speed_;
				int kind_;
				int frame{ 0 };
				bool disposable_{ false };
				std::shared_ptr<IPosition> position_;
			public:
				explicit Corpse(std::shared_ptr<IPosition> position, int move_speed,int image);
				void run() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() { return disposable_; }
				int getImage() override { return image_; }
			};
		}
	}
}