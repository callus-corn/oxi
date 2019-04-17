#pragma once

#include "../i_gate_factory.hpp"

namespace oxi
{
	class IController;

	namespace scene
	{
		namespace object
		{
			class GateFactory :public IGateFactory
			{
			private:
				std::shared_ptr<IController> controller_;
			public:
				explicit GateFactory(std::shared_ptr<IController> controller) :controller_(controller) {}
				std::vector<std::shared_ptr<IGate>> create(std::string scene_name) override;
			};
		}
	}
}