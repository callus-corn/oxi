#pragma once

#include "../i_object.hpp"

namespace oxi
{
	namespace scene
	{
		class IPosition;

		namespace object
		{
			class Wall:public IObject
			{
			private:
				std::shared_ptr<IPosition> position_;
				int kind_;
			public:
				Wall(std::shared_ptr<IPosition> position);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
			};
		}
	}
}