#pragma once

#include "sequence.hpp"

namespace oxi 
{
	class Game 
	{
	private:
		const Sequence sequence{};
	public:
		Game();
		virtual ~Game();
		void start() const;
	};
}