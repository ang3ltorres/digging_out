#include "game/level.hpp"
#include "game/game.hpp"

using namespace glm;
using namespace game;

int Level::width  = 0;
int Level::height = 0;
int Level::row    = 0;

unsigned short *Level::data = nullptr;

Utils::Alarm Level::alarm = Utils::Alarm(0.5f, [](){
	// printf("ALARM!!");
	return;
});

ivec4 Level::rectAux = {0, 0, 0, 0};

void Level::init(int width, int height)
{
	Level::width  = width;
	Level::height = height;
	Level::row    = 0;
	Level::data   = new unsigned short[width * height];

	for (int i = 0; i < width * height; i++)
		Level::data[i] = (Utils::random() > 0.5f) ? blockDefault : blockEmpty;
}

void Level::free()
{
	delete[] data;
	data = nullptr;
}

void Level::update()
{
	Level::alarm.update();
}

void Level::draw()
{
	for (int x = 0; x < width; x++)
	for (int y = 0; y < height; y++)
	{
		unsigned short packed  =  data[getBlock(x, y)];
		unsigned char  block   =  packed        & 0xFF; // bits 0-7
 // unsigned char  variant = (packed >> 8)  & 0xFF; // bits 8-15

		if (block == 0xFF)
		{
			Game::sprite->dst = {x * 32, y * 32, 32, 32};
			Game::sprite->src = {Utils::randomRange(0, 5) * 32, 0, 32, 32};
			Game::sprite->updateModel();
			Game::sprite->batch();
			Game::sprite->texture->draw();
		}
			// DrawRectangle(x * 32, y * 32, 32, 32, GREEN);
	}
}

bool Level::collision(ivec4 &rect)
{
	int startX = int(std::floor(rect.x / 32.0f));
	int endX   = startX + int(std::ceil(rect.z / 32.0f));

	int startY = int(std::floor(rect.y / 32.0f));
	int endY   = startY + int(std::ceil(rect.w / 32.0f));

	for (int x = startX; x <= endX; x++)
	for (int y = startY; y <= endY; y++)
	{
		if (x < 0 or x >= width or y < 0 or y >= height)
			continue;

		unsigned short packed = data[getBlock(x, y)];
		unsigned char  block  =  packed        & 0xFF; // bits 0-7

		rectAux = {x * 32, y * 32, 32, 32};

		if (block == 0xFF and Utils::collisionRect(rectAux, rect))
			return true;
	}

	return false;
}

unsigned short Level::getBlock(int x, int y)
{
	return ((y + row) % height) * width + x;
}