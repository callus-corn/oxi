#pragma once

#include <memory>
#include "i_controllable.hpp"

namespace oxi 
{
	class IController
	{
	public:
		virtual void update() {}
		virtual void setControllable(std::shared_ptr<IControllable> setted_controllable) {}
	};
}