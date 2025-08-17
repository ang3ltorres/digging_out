#include "game/game.hpp"

using namespace glm;
using namespace core;
using namespace game;

RenderTexture *Game::renderTexture;
Texture *Game::texture;
Sprite *Game::sprite;

void Game::init(int width, int height)
{
	Graphics::initialize(width, height, "OpenGL");
	Game::renderTexture = new RenderTexture{800, 600};

	Game::texture = new Texture("../res/main.png", 1);
	Game::sprite = new Sprite(0, 0, Game::texture, 0, 0, 32, 6, 0.5f);

	while (!Graphics::shouldClose())
	{
		Game::update();
		Game::draw();
		Graphics::endFrame();
	}
}

void Game::free()
{
	delete Game::renderTexture;
	Graphics::finalize();
}

void Game::update()
{
	printf("Delta Time: %.4f\tFPS: %.4f\n", Graphics::deltaTime, Graphics::fps);

	// Update logic

	if (Input::keyboardStates[GLFW_KEY_ESCAPE])
		Graphics::forceClose = true;
}

void Game::draw()
{
	// Render to target
	Graphics::setRenderTexture(Game::renderTexture);
	Graphics::clearScreen({255, 0, 255});

	Game::sprite->draw();

	// Render to default "canvas"
	Graphics::setRenderTexture();
	Graphics::clearScreen({255, 143, 119});

	Game::renderTexture->batch();
	Game::renderTexture->texture->draw();
}