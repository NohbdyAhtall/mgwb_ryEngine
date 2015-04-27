#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include <GL/glew.h>
#include <string>

namespace ryEngine
{

class GLSLProgram
{
    public:
        GLSLProgram();
        virtual ~GLSLProgram();

        void compileShaders(const std::string& vertexShaderFilePath, const std::string fragmentShaderFilePath);

        void linkShaders();

        void addAttribute(const std::string& attributeName);

        GLuint getUniformLocation(const std::string& uniformName);

        void use();
        void unuse();

    private:
        int _numAttributes;

        void compileShader(const std::string& filePath, GLuint id);

        GLuint _programID;

        GLuint _vertexShaderID;
        GLuint _fragmentShaderID;

};

}

#endif // GLSLPROGRAM_H
