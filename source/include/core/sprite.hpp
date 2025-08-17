#pragma once

#include "pch.hpp"
#include "core/drawable.hpp"
#include "game/utils.hpp"

namespace core
{
	class Sprite : public Drawable
	{
	public:
		Sprite(int x, int y, Texture *texture, int txr_x, int txr_y, int size, int frames = 1, float speed = 0.0f);
		Sprite(const Sprite&) = delete;
		~Sprite() = default;

		int txr_x;
		int txr_y;
		int size;
		int frames;

		void update();
		void draw();
	
		int currentFrame;
		game::Utils::Alarm alarm;
	};
}
