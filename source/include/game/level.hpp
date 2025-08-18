#pragma once

#include <pch.hpp>
#include "game/utils.hpp"

namespace game
{
	class Level
	{
	public:
		Level() = delete;
		static void init(int width, int height);
		static void free();

		static void update();
		static void draw();

		static bool collision(glm::vec4 rect);

		static int width;
		static int height;
		static int row;
		static unsigned short *data;

		static Utils::Alarm alarm;

		static constexpr unsigned short blockEmpty = 0x0000;
		static constexpr unsigned short blockDefault = 0x00FF;

	private:
		static unsigned short getBlock(int x, int y);
		static glm::vec4 rectAux;
	};
}
