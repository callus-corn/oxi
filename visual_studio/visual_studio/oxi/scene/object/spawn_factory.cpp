#include "spawn_factory.hpp"
#include "../../game_const.hpp"
#include "../scene_const.hpp"
#include "object_const.hpp"
#include "object_kind.hpp"
#include "position.hpp"
#include "spawn_mock_background.hpp"
#include "spawn_mock_object.hpp"
#include "spawn_mock_enemy.hpp"
#include "spawn_mock_ground.hpp"
#include "spawn_wall.hpp"
#include "gun.hpp"
#include "animation_death.hpp"
#include "animation_defeat.hpp"

std::vector<std::shared_ptr<oxi::scene::ISpawn>> oxi::scene::object::SpawnFactory::create(std::string scene_name)
{
	if (scene_name == oxi::scene::SceneConst::title_scene_name) 
	{
		std::vector<std::shared_ptr<oxi::scene::ISpawn>> spawns{};
		return spawns;
	}
	else if(scene_name == oxi::scene::SceneConst::debug_scene_name)
	{
		auto background_position = std::make_shared<Position>(0, 0, 0, 0);
		auto ground_position = std::make_shared<Position>(0, oxi::GameConst::window_y-oxi::scene::object::ObjectConst::unit_y*2, oxi::GameConst::window_x, oxi::GameConst::window_y*10);
		auto object_position = std::make_shared<Position>(oxi::GameConst::window_x/4, oxi::GameConst::window_y/2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y*2);
		auto enemy_position = std::make_shared<Position>(oxi::GameConst::window_x*3/4, oxi::GameConst::window_y/2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y*2);
		auto right_wall_position = std::make_shared<Position>(-oxi::GameConst::window_x, 0, oxi::GameConst::window_x, oxi::GameConst::window_y);
		auto left_wall_position = std::make_shared<Position>(oxi::GameConst::window_x, 0, oxi::GameConst::window_x, oxi::GameConst::window_y);
		auto enemy_positions = std::make_shared<std::vector<std::shared_ptr<IPosition>>>();
		std::vector<std::shared_ptr<ISpawn>> spawns
		{
			std::make_shared<SpawnMockBackGround>(background_position),
			std::make_shared<SpawnMockGround>(ground_position),
			std::make_shared<SpawnMockEnemy>(enemy_position,enemy_positions),
			std::make_shared<SpawnMockObject>(object_position,controller_),
			std::make_shared<SpawnWall>(right_wall_position),
			std::make_shared<SpawnWall>(left_wall_position),
			std::make_shared<AnimationDefeat>(enemy_positions,oxi::scene::object::ObjectConst::up),
			std::make_shared<AnimationDefeat>(enemy_positions,oxi::scene::object::ObjectConst::down),
			std::make_shared<Gun>(object_position,controller_),
			std::make_shared<AnimationDeath>(object_position,controller_,oxi::scene::object::ObjectConst::up),
			std::make_shared<AnimationDeath>(object_position,controller_,oxi::scene::object::ObjectConst::down),
		};
		return spawns;
	}
	else
	{
		std::vector<std::shared_ptr<oxi::scene::ISpawn>> spawns{};
		return spawns;
	}
}