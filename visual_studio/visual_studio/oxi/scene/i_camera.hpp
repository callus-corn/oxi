#pragma once

#include "i_object.hpp"

namespace oxi
{
	namespace scene
	{
		class IPosition;

		class ICamera : public IObject
		{
		public:
			virtual ~ICamera() {}
			virtual void ready() {}
			virtual void render(std::shared_ptr<IPosition> position,int image,int kind) {}
			virtual void refresh() {}
		};
	}
}