#pragma once

#include <map>

using Key = int;
using Frame = int;

namespace oxi
{
	class IControllable
	{
	public:
		virtual ~IControllable() {}
		virtual void update(std::map<Key,Frame> input) {}
	};
}