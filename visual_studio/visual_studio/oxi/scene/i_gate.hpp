#pragma once

#include <string>
#include "i_object.hpp"

namespace oxi
{
	namespace scene
	{
		class IGate:public IObject
		{
		public:
			virtual ~IGate() {}
			virtual bool isOpen() = 0;
			virtual std::string getNextSceneName() = 0;
		};
	}
}