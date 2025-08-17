#pragma once

#include "pch.hpp"

#include "core/renderTexture.hpp"
#include "core/font.hpp"

namespace core
{
	class Text
	{
	public:
		Text(core::Font *font, const char *text, float gap = 1.0f);
		Text(const Text &) = delete;
		~Text();

		core::Font *font;
		core::RenderTexture *renderTexture;

		void render(const char *text);
		float gap;
	};
}

