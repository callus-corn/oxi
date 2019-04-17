#pragma once

#include "../i_object.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class MockBackGround :public IObject
			{
			private:
				int image_;
				int kind_;
				std::shared_ptr<IPosition> position_;
			public:
				MockBackGround(std::shared_ptr<IPosition> position);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				void draw() override;
			};
		}
	}
}