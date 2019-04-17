#include "spawn_factory.hpp"
#include "../../game_const.hpp"
#include "../scene_const.hpp"
#include "object_const.hpp"
#include "position.hpp"
#include "spawn_mock_background.hpp"
#include "spawn_mock_object.hpp"
#include "spawn_mock_enemy.hpp"
#include "spawn_mock_ground.hpp"
#include "spawn_bullet.hpp"

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
		auto ground_position = std::make_shared<Position>(0, oxi::GameConst::window_y-oxi::scene::object::ObjectConst::unit_y/2, oxi::GameConst::window_x, oxi::scene::object::ObjectConst::unit_y / 2);
		auto object_position = std::make_shared<Position>(0, oxi::GameConst::window_y/2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y);
		auto bullet_position = object_position;
		auto enemy_position = std::make_shared<Position>(oxi::GameConst::window_x/2, oxi::GameConst::window_y/2, oxi::scene::object::ObjectConst::unit_x, oxi::scene::object::ObjectConst::unit_y);
		std::vector<std::shared_ptr<ISpawn>> spawns
		{
			std::make_shared<SpawnMockBackGround>(background_position),
			std::make_shared<SpawnMockGround>(ground_position),
			std::make_shared<SpawnMockEnemy>(enemy_position),
			std::make_shared<SpawnMockObject>(object_position,controller_),
			std::make_shared<SpawnBullet>(bullet_position,controller_),
		};
		return spawns;
	}
	else
	{
		std::vector<std::shared_ptr<oxi::scene::ISpawn>> spawns{};
		return spawns;
	}
}