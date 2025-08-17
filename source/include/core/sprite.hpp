#pragma once

#include "pch.hpp"

#include "core/drawable.hpp"

namespace core
{
	class Sprite : public Drawable
	{
	public:
		Sprite(const Sprite&) = default;
		Sprite(Texture *texture, glm::ivec4 src, glm::ivec4 dst);
		Sprite(Texture *texture, glm::ivec4 dst);
		Sprite(Texture *texture);
		~Sprite() = default;
	};
}
