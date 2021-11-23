#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GLES2/gl2.h>

class Shader
{
    public:
        Shader(const char* vertFile, const char* fragFile);
        ~Shader();

        void useProgram();

    private:
        bool isShaderCompiled(GLuint shaderId);
        void printInfoLog(GLuint shaderId);
        std::string getFile(const char* fileName);

        GLuint id;
};

#endif
