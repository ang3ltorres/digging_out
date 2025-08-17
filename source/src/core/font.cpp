#include "core/font.hpp"
#include "core/texture.hpp"

using namespace core;

Font::Font(const char *fontPath, unsigned int fontSize)
: Drawable::Drawable( new Texture{fontPath, fontSize, glyphs, 16} ), fontSize(fontSize)
{}

Font::~Font()
{
	delete texture;
}
