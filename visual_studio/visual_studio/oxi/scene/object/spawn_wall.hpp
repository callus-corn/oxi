#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class SpawnWall:public ISpawn
			{
			private:
				int kind_;
				std::shared_ptr<IPosition> position_;
				bool creatable_{ true };
			public:
				SpawnWall(std::shared_ptr<IPosition> position);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				bool isCreatable() { return creatable_; }
				int getKind() override { return kind_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}