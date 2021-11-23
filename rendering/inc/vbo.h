#ifndef VBO_H
#define VBO_H

#include <vector>
#include "GLES2/gl2.h"

class Vbo
{
    public:
        struct VertexAttribPointer
        {
            GLint size;
            GLsizei stride;
            int position;
        };
        
        Vbo();
        ~Vbo();
        Vbo& operator=(const Vbo& other) = delete;
        Vbo(const Vbo& other) = delete;

        void setBufferData(const std::vector<GLfloat>& bufferData);
        void setVertexAttribPointers(const std::vector<VertexAttribPointer> vertexAttribPointers);
        void bind();
        void unBind();

    private:
        GLuint id_;
        std::vector<VertexAttribPointer> vertexAttribPointers_;
};

#endif
