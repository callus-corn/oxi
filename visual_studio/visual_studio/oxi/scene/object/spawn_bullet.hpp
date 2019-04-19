#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	class IController;
	namespace scene
	{
		namespace object
		{
			class SpawnBullet :public ISpawn
			{
			private:
				int kind_;
				int move_speed_;
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IController> controller_;
			public:
				SpawnBullet(std::shared_ptr<IPosition> position, std::shared_ptr<IController> controller);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void run() override;
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override;
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}