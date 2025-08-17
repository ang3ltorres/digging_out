#pragma once

#include "core/graphics.hpp"
#include "game/utils.hpp"

namespace game
{
	class Game
	{
	public:
		Game() = delete;
		Game(const Game &) = delete;

		static void init(int width, int height);
		static void free();

		static void update();
		static void draw();

		static core::RenderTexture *renderTexture;
		
		static core::Texture *texture;
		static core::Sprite *sprite;
	};
}