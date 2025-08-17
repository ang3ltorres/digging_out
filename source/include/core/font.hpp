#pragma once

#include "pch.hpp"
#include "core/drawable.hpp"

namespace core
{
	class Font : public Drawable
	{
	public:

		struct Glyph
		{
			glm::vec2 bearing;   // Offset from baseline to top-left of glyph
			glm::vec2 size;      // Size of the glyph in pixels
			glm::ivec2 atlasPos; // Position in the texture atlas
			float advance;       // Horizontal offset to advance to next glyph
		};

		Font(const char *fontPath, unsigned int fontSize);
		Font(const Font &) = delete;
		~Font();

		Font::Glyph glyphs[96]; // Printable characters (32 - 127)
		unsigned int fontSize;
	};
}

