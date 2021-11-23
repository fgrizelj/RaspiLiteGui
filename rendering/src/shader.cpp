#include "shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(const char* vertFile, const char* fragFile)
{
    std::string vertString = getFile(vertFile);
    std::string fragString = getFile(fragFile);
    const char* vertContent = vertString.c_str();
    const char* fragContent = fragString.c_str();

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertContent, NULL);
    glCompileShader(vertShader);

    if(!isShaderCompiled(vertShader))
    {
        printInfoLog(vertShader);
    }

    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragContent, NULL);
    glCompileShader(fragShader);

    if(!isShaderCompiled(fragShader))
    {
        printInfoLog(fragShader);
    }

    id = glCreateProgram();
    glAttachShader(id, vertShader);
    glAttachShader(id, fragShader);

    glLinkProgram(id);

    GLint programLinked;
    glGetProgramiv(id, GL_LINK_STATUS, &programLinked);
    if(programLinked == 0)
    {
        GLint returnedLength;
        GLchar infoLog[1024];
        glGetProgramInfoLog(id, 1024, &returnedLength, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}

void Shader::useProgram()
{
    glUseProgram(id);
}

Shader::~Shader()
{
    glDeleteProgram(id);
}

bool Shader::isShaderCompiled(GLuint shaderId)
{
    GLint compiled;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);
    return compiled == 1;
}

void Shader::printInfoLog(GLuint shaderId)
{
    GLint returnedLength;
    GLchar infoLog[1024];
    glGetShaderInfoLog(shaderId, 1024, &returnedLength, infoLog);
    std::cout << infoLog << std::endl;
}

std::string Shader::getFile(const char* filename)
{
    std::ifstream ifs(filename);
    std::string content( (std::istreambuf_iterator<char>(ifs)),
                         (std::istreambuf_iterator<char>())
                       );
    return content;
}
