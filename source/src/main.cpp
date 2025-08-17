#include "core/graphics.hpp"

int main()
{
	unsigned int width = 1280;
	unsigned int height = 720;
	
	core::Graphics::initialize(width, height, "OpenGL");
	
	core::RenderTexture *renderTexture = new core::RenderTexture{800, 600};

	core::Font *font = new core::Font{"../res/mononoki-Bold.ttf", 90};

	// auto it = font->glyphs->find('p');
	// const core::Glyph &glyph = it->second;
	// font->src =
	// {
	// 	glyph.atlasPos.x,
	// 	glyph.atlasPos.y,
	// 	glyph.size.x,
	// 	glyph.size.y
	// };

	// font->dst =
	// {
	// 	128,
	// 	128,
	// 	glyph.size.x,
	// 	glyph.size.y
	// };

	// font->updateModel();

	core::Text *text = new core::Text{font, "Hello world!!"};

	// renderTexture->dst.z *= 1;
	// renderTexture->dst.w *= 1;
	// renderTexture->updateModel();

	// svgSprite->dst.z *= 4;
	// svgSprite->dst.w *= 4;
	// svgSprite->updateModel();

	while (!core::Graphics::shouldClose())
	{
		// Update logic

		if (Input::keyboardStates[GLFW_KEY_ESCAPE])
			core::Graphics::forceClose = true;

		// core::Graphics::currentCamera->move({1, 0});
		// rect->sprite->texture->updateUBO();

		// Render to target
		core::Graphics::setRenderTexture(renderTexture);
		core::Graphics::clearScreen({255, 0, 255});

		//rect->sprite->batch();
		//rect->sprite->texture->draw();

		// Render to default "canvas"
		core::Graphics::setRenderTexture();
		core::Graphics::clearScreen({255, 143, 119});
		
		renderTexture->batch();
		renderTexture->texture->draw();

		// font->batch();
		// font->texture->draw();

		text->renderTexture->batch();
		text->renderTexture->texture->draw();

		// svgSprite->batch();
		// svgSprite->texture->draw();

		// rect->sprite->batch();
		// rect->sprite->texture->draw();

		core::Graphics::endFrame();
	}

	delete font;
	delete renderTexture;

	core::Graphics::finalize();
	return 0;
}