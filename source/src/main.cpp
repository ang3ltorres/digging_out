#include "core/graphics.hpp"
#include "game/game.hpp"

using namespace game;

int main()
{
	Game::init(1280, 720);
	Game::free();
	return 0;
}