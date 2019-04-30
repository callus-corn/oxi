#pragma once

#include "../i_spawn.hpp"
#include <vector>

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class AnimationDefeat :public ISpawn
			{
			private:
				int kind_;
				int direction_;
				bool creatable_{ false };
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<std::vector<std::shared_ptr<IPosition>>> object_positions_;
			public:
				explicit AnimationDefeat(std::shared_ptr<std::vector<std::shared_ptr<IPosition>>> object_positions, int direction);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void collision() override;
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override { return creatable_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}