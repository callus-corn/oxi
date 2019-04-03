#pragma once

using X = int;
using Y = int;

namespace oxi 
{
	namespace scene 
	{
		namespace game_object
		{
			class Position 
			{
			private:
				X x;
				Y y;
			public:
				explicit Position(X constractor_x,Y constractor_y):x(constractor_x),y(constractor_y) {}
				void addX(X difference_x) { x += difference_x; }
				void addY(Y difference_y) { y += difference_y; }
				void moveTo(X destination_x,Y destination_y) 
				{
					x = destination_x;
					y = destination_y;
				}
				X getX() { return x; }
				Y getY() { return y; }
			};
		}
	}
}