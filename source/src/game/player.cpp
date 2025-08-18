#include "game/player.hpp"
#include "core/graphics.hpp"
#include "game/game.hpp"

using namespace glm;
using namespace core;
using namespace game;

Player::Player(int x, int y)
: Sprite::Sprite(x, y, Game::texture, 1 * 32, 0, 32), ySpeed(0.0f), isGrounded(false)
{
	
}

void Player::update()
{
	static constexpr float gravity = 500.0f;
	static constexpr int tileSize = 32;

	dst.y += ySpeed * Graphics::deltaTime;

	if (ySpeed >= 0 && Level::collision(dst))
	{
		dst.y = std::floor(dst.y / tileSize) * tileSize;

		ySpeed = 0.0f;
		isGrounded = true;
	}
	else
	{
		ySpeed += gravity * Graphics::deltaTime;
		isGrounded = false;
	}

	updateModel();
}

void Player::draw()
{
	batch();
	texture->draw();
	alarm.update();
}
