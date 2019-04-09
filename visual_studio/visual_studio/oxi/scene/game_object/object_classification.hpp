#pragma once

using Kind = int;

namespace oxi
{
	namespace scene
	{
		namespace game_object 
		{
			struct ObjectClassification
			{
				static const Kind player;
				static const Kind ground;
				static const Kind enemy;
				static const Kind bullet;
				static const Kind scene_switch;
				static const Kind back_ground;
			};
		}
	}
}