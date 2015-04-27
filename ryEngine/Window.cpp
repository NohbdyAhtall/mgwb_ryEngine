#include "Window.h"

namespace ryEngine
{

Window::Window()
{
}

Window::~Window()
{
}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
{
    Uint32 flags = SDL_WINDOW_OPENGL;

    if (currentFlags & INVISIBLE)
    {
        flags |= SDL_WINDOW_HIDDEN;
    }
    if (currentFlags & FULLSCREEN)
    {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    if (currentFlags & BORDERLESS)
    {
        flags |= SDL_WINDOW_BORDERLESS;
    }

    _sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);

    if (_sdlWindow == nullptr)
    {
        fatalError("SDL window could not be created!");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
    if (glContext == nullptr)
    {
        fatalError("SDL_GL context could not be created!");
    }

    GLenum error = glewInit();
    if(error != GLEW_OK)
    {
        fatalError("Could not initialize glew!");
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    SDL_GL_SetSwapInterval(0);

    // Enable Alpha blending
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return 0;
}

void Window::swapBuffer()
{
    SDL_GL_SwapWindow(_sdlWindow);
}


//Method for changing the Window's Background color, 2015 Apr22(Formerly was hard-coded)
void Window::changeWinBackGround(float bg_r, float bg_g, float bg_b, float bg_a)
{
    glClearColor(bg_r, bg_g, bg_b, bg_a);

}

}
