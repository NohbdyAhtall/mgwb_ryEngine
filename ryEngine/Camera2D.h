#ifndef CAMERA2D_H
#define CAMERA2D_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ryEngine
{

class Camera2D
{
public:
    Camera2D();
    ~Camera2D();

    void init(int screenWidth, int screenHeight);

    void update();

    glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

    void setPosition(const glm::vec2& newPosition) { _position = newPosition; _needsMatrixUpdate = true; };//CHANGE: No &reference for vec2
    void setScale(float newScale)                  { _scale = newScale; _needsMatrixUpdate = true;       };

    glm::vec2 getPosition()     { return _position;      }
    float getScale()            { return _scale;         }
    glm::mat4 getCameraMatrix() { return _cameraMatrix;  }

private:
    int         _screenWidth, _screenHeight;
    bool        _needsMatrixUpdate;
    float       _scale;
    glm::vec2   _position;
    glm::mat4   _cameraMatrix;
    glm::mat4   _orthoMatrix;
};

}
#endif // CAMERA2D_H
