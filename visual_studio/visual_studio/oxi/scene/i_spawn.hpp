#pragma once

#include <memory>
#include "i_object.hpp"

namespace oxi
{
	namespace scene 
	{
		class ISpawn:public IObject
		{
		public:
			virtual ~ISpawn() {}
			virtual bool isCreatable() = 0;
			virtual std::shared_ptr<IObject> create() = 0;
		};
	}
}