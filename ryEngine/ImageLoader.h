#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "GLTexture.h"

namespace ryEngine
{

class ImageLoader
{
    public:
        static GLTexture loadPNG(std::string filePath);
};

}
#endif // IMAGELOADER_H
