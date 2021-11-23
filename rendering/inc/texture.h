#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include "GLES2/gl2.h"

class Texture
{
    public:
        Texture(const char* imageFileName);
        ~Texture();

        void bind();
        void unBind();

    private:
        GLuint id_;
};

#endif
