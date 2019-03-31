#pragma once

namespace oxi
{
	namespace scene 
	{
		class IGameObject
		{
		public:
			virtual ~IGameObject() {}
			virtual void run() {}
			virtual void draw() {}
		};
	}
}