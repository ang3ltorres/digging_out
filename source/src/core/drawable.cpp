#include "core/drawable.hpp"
#include "core/texture.hpp"

using namespace core;
using namespace glm;

Drawable::Drawable(Texture *texture)
: texture(texture), src({0, 0, texture->width, texture->height}), dst({0, 0, texture->width, texture->height}), color({255, 255, 255, 255}), rotation(0.0f)
{
	updateModel();
}

void Drawable::updateModel()
{
	model =
	{
		translate(mat4(1.0f), vec3(dst.x, dst.y, 0.0f))
			*
		rotate(mat4(1.0f), radians(rotation), {0.0f, 0.0f, 1.0f})
			*
		scale(mat4(1.0f), vec3(dst.z, dst.w, 1.0f))
	};
}

void Drawable::batch()
{
	texture->SSBO_Data[texture->currentInstance++] =
	{
		{src.x / (float)texture->width, src.y / (float)texture->height, src.z / (float)texture->width, src.w / (float)texture->height},
		{vec4{color.r, color.g, color.b, color.a}},
		{model},
	};
}

