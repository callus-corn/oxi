#pragma once

namespace oxi
{
	namespace scene 
	{
		class IGameObject
		{
		public:
			virtual void run() {}
			virtual void draw() {}
		};
	}
}