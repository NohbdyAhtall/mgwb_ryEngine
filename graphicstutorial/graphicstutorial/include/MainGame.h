#ifndef MAINGAME_H
#define MAINGAME_H

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <ryEngine/ryEngine.h>
#include <ryEngine/GLSLProgram.h>
#include <ryEngine/GLTexture.h>
#include <ryEngine/Sprite.h>
#include <ryEngine/Window.h>
#include <ryEngine/InputManager.h>
#include <ryEngine/Timing.h>

#include <ryEngine/SpriteBatch.h>

#include <ryEngine/Camera2D.h>

#include "Bullet.h"

#include <vector>

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
    MainGame();
    virtual ~MainGame();

    void run();

private:
    void initSystems();
    void initShaders();
    void gameLoop();
    void processInput();
    void drawGame();

    ryEngine::Window    _window;
    int                 _screenWidth;
    int                 _screenHeight;
    GameState           _gameState;

    ryEngine::GLSLProgram   _colorProgram;
    ryEngine::Camera2D      _camera;

    ryEngine::SpriteBatch   _spriteBatch;

    ryEngine::InputManager  _inputManager;
    ryEngine::FpsLimiter    _fpsLimiter;

    std::vector<Bullet> _bullets;

    float   _maxFPS;
    float   _fps;
    float   _time;
};

#endif // MAINGAME_H
