#pragma once

#include "i_scene.hpp"

namespace oxi 
{
	class Sequence;

	class TitleScene : public IScene
	{
	private:
		Sequence* const sequence;
	public:
		explicit TitleScene(Sequence* constructor_sequence) :sequence(constructor_sequence) {}
		virtual ~TitleScene() {}
		void calculate() override;
		void draw() override;
	};
}