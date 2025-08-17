#include "game/utils.hpp"
#include "core/graphics.hpp"

using namespace glm;
using namespace core;
using namespace game;

std::mt19937 Utils::gen(std::random_device{}());
std::uniform_real_distribution<float> Utils::dist(0.0f, 1.0f);
std::uniform_int_distribution<int> Utils::distInt(0, 1);

float Utils::random()
{
	return dist(gen);
}

int Utils::randomRange(int min, int max)
{
	distInt.param(std::uniform_int_distribution<int>::param_type(min, max));
	return distInt(gen);
}

bool Utils::collisionRect(ivec4 &r1, ivec4 &r2)
{
	return !(r1.x + r1.z <= r2.x ||
					 r1.x >= r2.x + r2.z ||
					 r1.y + r1.w <= r2.y ||
					 r1.y >= r2.y + r2.w);
}

Utils::Alarm::Alarm(float timeTarget, std::function<void()> func)
: func(func), timeTarget(timeTarget), timeCurrent(0.0f)
{ }

void Utils::Alarm::update()
{
	timeCurrent += Graphics::deltaTime;
	while (timeCurrent >= timeTarget)
	{
		func();
		timeCurrent -= timeTarget;
	}
}
