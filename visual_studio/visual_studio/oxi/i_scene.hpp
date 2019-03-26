#pragma once

#include "Dxlib.h"

namespace oxi 
{
	class IScene 
	{
	public:
		virtual ~IScene() {}
		virtual void calculate() {}
		virtual void draw() {}
	};
}