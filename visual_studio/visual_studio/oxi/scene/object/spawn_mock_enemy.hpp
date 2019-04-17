#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class SpawnMockEnemy :public ISpawn
			{
			private:
				int kind_;
				std::shared_ptr<IPosition> position_;
				bool creatable_{ true };
			public:
				SpawnMockEnemy(std::shared_ptr<IPosition> position);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override { return creatable_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}