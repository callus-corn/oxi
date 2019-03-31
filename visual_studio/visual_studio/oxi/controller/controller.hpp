#pragma once

#include "../i_controller.hpp"

namespace oxi
{
	namespace controller 
	{
		class Controller :public IController
		{
		private:
			std::map<Key, Frame> key_map{};
			std::shared_ptr<IControllable> controllable;
		public:
			void update() override;
			void setControllable(std::shared_ptr<IControllable> setted_controllable) override { controllable = setted_controllable; }
		};
	}
}