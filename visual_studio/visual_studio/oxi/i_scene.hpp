#pragma once

#include <string>

namespace oxi 
{
	class IScene 
	{
	public:
		virtual void run() {}
		virtual bool isStopped() = 0;
		virtual std::string getNextSceneName() = 0;
	};
}