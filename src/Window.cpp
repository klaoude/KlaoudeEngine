#include "Window.h"
#include "Errors.h"

namespace KlaoudeEngine
{
	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;
		m_screenWidth = screenWidth;
		m_screenHeight = screenHeight;

		if (currentFlags & INVISIBLE)
			flags |= SDL_WINDOW_HIDDEN;
		if (currentFlags  & FULLSCREEN)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		if (currentFlags & BORDERLESS)
			flags |= SDL_WINDOW_BORDERLESS;

		m_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);

		if (m_sdlWindow == nullptr)
			fatalError("SDL window could not be created !");

		SDL_GLContext glContex = SDL_GL_CreateContext(m_sdlWindow);
		if (glContex == nullptr)
			fatalError("SDL contex could not be created !");

		GLenum error = glewInit();
		if (error != GLEW_OK)
			fatalError("glew could not be init !");

		std::printf("*** OpenGL Version: %s ***", glGetString(GL_VERSION));

		glClearColor(0.0f, 0.0f, 1.0f, 0.1f);

		SDL_GL_SetSwapInterval(0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return 0;
	}

	void Window::swapBuffer()
	{
		SDL_GL_SwapWindow(m_sdlWindow);
	}
}