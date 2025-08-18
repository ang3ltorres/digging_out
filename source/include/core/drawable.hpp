#pragma once

#include "pch.hpp"
#include "core/color.hpp"

namespace core
{
	class Texture;

	class Drawable
	{
	public:
		Drawable(Texture *texture);
		Drawable(const Drawable&) = delete;
		~Drawable() = default;

		Texture *texture;
		
		glm::vec4 src;
		glm::vec4 dst;
		Color color;
		float rotation;

		void updateModel();
		void batch();

		glm::mat4 model;
	};
}
