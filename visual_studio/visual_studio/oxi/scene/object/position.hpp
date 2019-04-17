#pragma once

#include "../i_position.hpp"

namespace oxi 
{
	namespace scene 
	{
		namespace object
		{
			class Position :public IPosition
			{
			private:
				int x_;
				int y_;
				int length_x_;
				int length_y_;
				std::vector<int> collisions_{};
			public:
				explicit Position(int x,int y,int length_x,int length_y)
					:x_(x),y_(y),length_x_(length_x),length_y_(length_y){}
				void addX(int difference) override { x_ += difference; }
				void addY(int difference) override { y_ += difference; }
				void moveTo(int x,int y) override
				{
					x_ = x;
					y_ = y;
				}
				bool isCollision(std::shared_ptr<IPosition> position) override 
				{
					return ( x_            < (position->getX()+position->getLengthX()))&&
						   ( y_            < (position->getY()+position->getLengthY()))&&
						   ((x_+length_x_) >  position->getX())&&
						   ((y_+length_y_) >  position->getY());
				}
				void addCollision(int kind) override { collisions_.push_back(kind); }
				int getX() override { return x_; }
				int getY() override { return y_; }
				int getLengthX() override { return length_x_; }
				int getLengthY() override { return length_y_; }
				std::vector<int> getCollisions() override { return collisions_; }
				void resetCollisions() override { collisions_.erase(collisions_.begin(),collisions_.end()); }
			};
		}
	}
}