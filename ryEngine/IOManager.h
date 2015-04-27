#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <fstream>
#include <string>
#include <vector>

namespace ryEngine
{

class IOManager
{
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
};

}

#endif // IOMANAGER_H
