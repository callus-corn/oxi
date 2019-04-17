#pragma once

#include "../i_controller.hpp"

namespace oxi
{
	namespace controller 
	{
		class Controller :public IController
		{
		private:
			std::map<int, int> key_map_{};
		public:
			void update() override;
			std::map<int, int> getInput() { return key_map_; }
		};
	}
}