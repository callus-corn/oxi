#pragma once

#include <map>

namespace oxi 
{
	class IController
	{
	public:
		virtual void update() {}
		virtual std::map<int,int> getInput() = 0;
	};
}