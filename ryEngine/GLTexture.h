#ifndef GLTEXTURE_H_INCLUDED
#define GLTEXTURE_H_INCLUDED

#include <GL/glew.h>
#include <string>

namespace ryEngine
{

struct GLTexture
{
    GLuint id;
    int width;
    int height;
};

}

#endif // GLTEXTURE_H_INCLUDED
