#pragma once

#include "i_scene.hpp"

namespace oxi 
{
	class Sequence;

	class PlayGroundScene:public IScene
	{
	private:
		Sequence* const sequence;
	public:
		explicit PlayGroundScene(Sequence* constructor_sequence) :sequence(constructor_sequence) {}
		virtual ~PlayGroundScene() {}
		void calculate() override;
		void draw() override;
	};
}