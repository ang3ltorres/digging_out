#pragma once

#include "core/sprite.hpp"

namespace game
{
	class Player : public core::Sprite
	{
	public:
		Player(int x, int y);

		void update();
		void draw();
	};
}
