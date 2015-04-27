#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <map>
#include "GLTexture.h"

namespace ryEngine
{

class TextureCache
{
public:
    TextureCache();
    ~TextureCache();

    GLTexture getTexture(std::string texturePath);

private:
    std::map<std::string, GLTexture> _textureMap;
};

}

#endif // TEXTURECACHE_H
