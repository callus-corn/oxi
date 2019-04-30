#pragma once

#include "../i_spawn.hpp"

namespace oxi
{
	class IController;
	namespace scene
	{
		namespace object
		{
			class Gun:public ISpawn
			{
			private:
				int kind_;
				bool active_{true};
				std::shared_ptr<IPosition> position_;
				std::shared_ptr<IPosition> object_position_;
				std::shared_ptr<IController> controller_;
			public:
				explicit Gun(std::shared_ptr<IPosition> object_position, std::shared_ptr<IController> controller);
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				void run() override;
				void collisionStore(std::shared_ptr<IPosition> position, int kind) override;
				void collision() override;
				int getKind() override { return kind_; }
				bool isDisposable() override { return false; }
				bool isCreatable() override;
				std::shared_ptr<IObject> create() override;
			};
		}
	}
}