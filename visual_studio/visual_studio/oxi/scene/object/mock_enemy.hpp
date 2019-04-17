#pragma once

#include <vector>
#include "../i_object.hpp"

namespace oxi
{
	namespace scene 
	{
		namespace object
		{
			class MockEnemy :public IObject
			{
			private:
				int image_;
				std::shared_ptr<IPosition> position_;
				int kind_;
				bool disposable_{ false };
				int frame_{ 0 };

			public:
				explicit MockEnemy(std::shared_ptr<IPosition> position);
				void run() override;
				void collisionStore(std::shared_ptr<IPosition> position, int kind) override;
				void collision() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() override { return disposable_; }
				void draw() override;
			};
		}
	}
}