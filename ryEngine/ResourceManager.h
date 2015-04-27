#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "TextureCache.h"
#include <string>

namespace ryEngine
{

class ResourceManager
{
public:
    static GLTexture getTexture(std::string texturePath);

private:
    static TextureCache _textureCache;
};

}

#endif // RESOURCEMANAGER_H
