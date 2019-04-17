#pragma once

#include <memory>
#include <vector>

namespace oxi
{
	namespace scene
	{
		class IPosition
		{
		public:
			virtual ~IPosition() {}
			virtual bool isCollision(std::shared_ptr<IPosition> position) = 0;
			virtual void addCollision(int kind) {}
			virtual void addX(int difference) {}
			virtual void addY(int difference) {}
			virtual void moveTo(int x,int y) {}
			virtual int getX() = 0;
			virtual int getY() = 0;
			virtual int getLengthX() = 0;
			virtual int getLengthY() = 0;
			virtual std::vector<int> getCollisions() = 0;
			virtual void resetCollisions() {}
		};
	}
}