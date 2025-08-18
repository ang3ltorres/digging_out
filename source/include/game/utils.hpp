#pragma once

#include <pch.hpp>

namespace game
{
	class Utils
	{
	public:
		static float random();
		static int randomRange(int min, int max);

		static bool collisionRect(glm::vec4 r1, glm::vec4 r2);
	
		struct Alarm
		{
			Alarm(float timeTarget, std::function<void()> func);
			Alarm(const Alarm &) = delete;
	
			std::function<void()> func;
			float timeTarget;
			float timeCurrent;
	
			void update();
		};
	
	private:
		static std::mt19937 gen;
		static std::uniform_real_distribution<float> dist;
		static std::uniform_int_distribution<int> distInt;
	};
}
