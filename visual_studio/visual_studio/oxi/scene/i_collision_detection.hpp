#pragma once

using X = int;
using Y = int;
using Length = int;
using Kind = int;

namespace oxi
{
	namespace scene
	{
		class ICollisionDetection
		{
		private:
			Length x_length;
			Length y_length;
			Kind kind;
		public:
			ICollisionDetection(Kind constractor_kind,Length constractor_x_length, Length constractor_y_length)
				:kind(constractor_kind),
				x_length(constractor_x_length),
				y_length(constractor_y_length) {}
			virtual ~ICollisionDetection() {}
			virtual X getX() = 0;
			virtual Y getY() = 0;
			Length getXLength() { return x_length; }
			Length getYLength() { return y_length; }
			Kind getKind() { return kind; }
		};
	}
}