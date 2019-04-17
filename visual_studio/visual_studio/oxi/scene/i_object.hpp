#pragma once

#include <memory>

namespace oxi
{
	namespace scene
	{
		class IPosition;

		class IObject
		{
		public:
			virtual ~IObject() {}
			virtual void run() {}
			virtual void collisionStore(std::shared_ptr<IPosition> position,int kind) {}
			virtual void collision() {}
			virtual std::shared_ptr<IPosition> getPosition() = 0;
			virtual int getKind() = 0;
			virtual bool isDisposable() = 0;
			virtual void draw() {}
		};
	}
}