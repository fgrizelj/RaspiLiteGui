#ifndef EBO_H
#define EBO_H

#include <vector>
#include "GLES2/gl2.h"

class Ebo
{
    public:
        Ebo();
        ~Ebo();
        Ebo& operator=(const Ebo& other) = delete;
        Ebo(const Ebo& other) = delete;

        void setBufferData(const std::vector<GLushort>& bufferData);
        void bind();
        void unBind();

    private:
        GLuint id_;
};

#endif
