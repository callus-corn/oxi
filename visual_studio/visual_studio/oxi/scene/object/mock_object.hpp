#pragma once

#include <memory>
#include <vector>
#include <string>
#include "../i_object.hpp"

namespace oxi
{
	class IController;

	namespace scene 
	{
		namespace object
		{
			class MockObject :public IObject
			{
			private:
				int image_;
				int kind_;
				int frame_{0};
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IController> controller_;
			public:
				explicit MockObject(std::shared_ptr<IPosition> position, std::shared_ptr<IController> controller);
				void run() override;
				void collisionStore(std::shared_ptr<IPosition> position,int kind) override;
				void collision() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void draw() override;
				bool isDisposable() override { return false; }
				int getKind() override { return kind_; }
			};
		}
	}
}