#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	class IController;

	namespace scene
	{
		namespace object
		{
			class SpawnMockObject :public ISpawn
			{
			private:
				int kind_;
				bool creatable_{ true };
				std::shared_ptr<IController> controller_;
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IPosition> player_position_;
				std::shared_ptr<IObject> player_;
			public:
				SpawnMockObject(std::shared_ptr<IPosition> player_position, std::shared_ptr<IController> controller);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override;
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}