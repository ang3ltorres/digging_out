#include "core/sprite.hpp"
#include "core/texture.hpp"

using namespace core;
using namespace glm;

Sprite::Sprite(int x, int y, Texture *texture, int txr_x, int txr_y, int size, int frames, float speed)
: Drawable::Drawable(texture), txr_x(txr_x), txr_y(txr_y), size(size), frames(frames), currentFrame(0), alarm(speed, [this]() { this->update(); })
{
	src = {(float)txr_x, (float)txr_y, (float)size, (float)size};
	dst = {(float)x,     (float)y,     (float)size, (float)size};
}

void Sprite::update()
{
	if (frames <= 1) return;

	src = {(float)(txr_x + (size * currentFrame)), (float)txr_y, (float)size, (float)size};

	if (currentFrame >= frames-1)
		currentFrame = 0;
	else
		currentFrame++;
}

void Sprite::draw()
{
	batch();
	texture->draw();

	alarm.update();
}
