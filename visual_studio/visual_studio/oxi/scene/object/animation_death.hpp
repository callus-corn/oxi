#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	class IController;

	namespace scene
	{
		namespace object
		{
			class AnimationDeath :public ISpawn
			{
			private:
				int kind_;
				int direction_;
				bool creatable_{false};
				bool active_{true};
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IPosition> object_position_;
				std::shared_ptr<IController> controller_;
			public:
				explicit AnimationDeath(std::shared_ptr<IPosition> object_position, std::shared_ptr<IController> controller,int direction);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void run() override;
				void collisionStore(std::shared_ptr<IPosition> position, int kind) override;
				void collision() override;
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override { return creatable_; }
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}