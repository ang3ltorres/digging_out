#pragma once

#include "core/sprite.hpp"

namespace game
{
	class Player : public core::Sprite
	{
	public:
		Player(int x, int y);
		
		float ySpeed;
		bool isGrounded;

		void update();
		void draw();
	};
}
