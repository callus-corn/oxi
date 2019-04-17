#include "gate_factory.hpp"
#include "../i_gate.hpp"
#include "../scene_const.hpp"
#include "position.hpp"
#include "title_back.hpp"
#include "mock_gate.hpp"
#include "object_const.hpp"

std::vector<std::shared_ptr<oxi::scene::IGate>> oxi::scene::object::GateFactory::create(std::string scene_name)
{
	if (scene_name == oxi::scene::SceneConst::title_scene_name) 
	{
		auto position = std::make_shared<Position>(0, 0, 0, 0);
		std::vector<std::shared_ptr<oxi::scene::IGate>> gates
		{
			std::make_shared<TitleBack>(position,controller_)
		};
		return gates;
	}
	else if(scene_name == oxi::scene::SceneConst::debug_scene_name)
	{
		auto position = std::make_shared<Position>(0, 0, oxi::scene::object::ObjectConst::unit_x*2, oxi::scene::object::ObjectConst::unit_y);
		std::vector<std::shared_ptr<oxi::scene::IGate>> gates
		{
			std::make_shared<MockGate>(position)
		};
		return gates;
	}
	else
	{
		std::vector<std::shared_ptr<oxi::scene::IGate>> gates{};
		return gates;
	}
}
