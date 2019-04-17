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
				std::shared_ptr<IController> controller_;
				std::shared_ptr<IPosition> position_;
				bool creatable_{ true };
			public:
				SpawnMockObject(std::shared_ptr<IPosition> position, std::shared_ptr<IController> controller);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override { return creatable_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}