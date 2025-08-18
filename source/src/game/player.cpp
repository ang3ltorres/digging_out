#include "game/player.hpp"
#include "core/graphics.hpp"
#include "game/game.hpp"

using namespace glm;
using namespace core;
using namespace game;

Player::Player(int x, int y)
: Sprite::Sprite(x, y, Game::texture, 1 * 32, 0, 32)
{
	
}

void Player::update()
{

}

void Player::draw()
{
	batch();
	texture->draw();
	alarm.update();
}
