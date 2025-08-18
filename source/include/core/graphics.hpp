#pragma once

#include "pch.hpp"

#include "core/color.hpp"
#include "core/input.hpp"
#include "core/shader.hpp"
#include "core/camera.hpp"
#include "core/texture.hpp"
#include "core/sprite.hpp"
#include "core/renderTexture.hpp"
#include "core/text.hpp"

namespace core
{
	class Graphics
	{
	public:
		Graphics() = delete;
		Graphics(const Graphics&) = delete;
		~Graphics() = default;

		static void initialize(int width, int height, const char *title);
		static void finalize();
		
		// Window
		static GLFWwindow *window;
		static unsigned int width;
		static unsigned int height;
		static bool forceClose;

		// Input
		static Input *input;

		// Default stuff
		static GLuint currentVAO;
		static GLuint currentTexture;
		static Camera *currentCamera;
		static Camera *defaultCamera;

		// Time Travel stuff
		static double fps;
		static double deltaTime;

		// Library Methods
		static bool shouldClose();
		static void clearScreen(const Color color);
		static void setRenderTexture(RenderTexture *renderTexture = nullptr);
		static void setVAO(GLuint VAO);
		static void setTexture(GLuint texture);
		static void endFrame();

	private:
		static double currentTime;
		static double lastTime;
	};
}