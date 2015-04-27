#include "Timing.h"

#include <SDL/SDL.h>

namespace ryEngine
{

FpsLimiter::FpsLimiter()
{

}

void FpsLimiter::init(float maxFPS)
{
    setMaxFPS(maxFPS);
}

void FpsLimiter::setMaxFPS(float maxFPS)
{
    _maxFPS = maxFPS;
}

void FpsLimiter::begin()
{
    _startTicks = SDL_GetTicks();
}

float FpsLimiter::end()
{
    calculateFPS();

    float frameTicks = SDL_GetTicks() - _startTicks;
    //Limit the FPS to the max FPS
    if (1000.0f / _maxFPS > frameTicks)
    {
        SDL_Delay((Uint32)(1000.0f / _maxFPS - frameTicks));
    }

    return _fps;
}

void FpsLimiter::calculateFPS()
{
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    static float previousTicks = SDL_GetTicks();

    float currentTicks;
    currentTicks = SDL_GetTicks();

    _frameTime = currentTicks - previousTicks;
    frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

    previousTicks = currentTicks;

    int counter;

    currentFrame++;
    if (currentFrame < NUM_SAMPLES)
    {
        counter = currentFrame;
    }
    else
    {
        counter = NUM_SAMPLES;
    }

    float frameTimeAverage = 0;
    for (int i = 0; i < counter; i++)
    {
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= counter;

    if (frameTimeAverage > 0)
    {
        _fps = 1000.0f / frameTimeAverage;
    }
    else
    {
        _fps = 60.0f;
    }
}







}
