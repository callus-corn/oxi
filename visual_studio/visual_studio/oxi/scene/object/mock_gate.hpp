#pragma once

#include "../i_gate.hpp"

namespace oxi
{
	namespace scene
	{
		namespace object
		{
			class MockGate:public IGate
			{
			private:
				int image_;
				std::shared_ptr<IPosition> position_;
				int kind_;
				std::string next_scene_name_{};

			public:
				explicit MockGate(std::shared_ptr<IPosition> position);
				void collisionStore(std::shared_ptr<IPosition> position, int kind) override;
				void collision() override;
				std::shared_ptr<IPosition> getPosition() override { return position_; }
				int getKind() override { return kind_; }
				bool isDisposable() { return false; }
				void draw() override;
				bool isOpen() override { return !next_scene_name_.empty(); };
				std::string getNextSceneName() override { return next_scene_name_; };
			};
		}
	}
}