#include "texture.h"
#include <cstddef>
#include "lodepng.h"
#include <iostream>

Texture::Texture(const char* imageFileName)
{
    std::vector<unsigned char> rawImage;
    unsigned width, height;
    lodepng::decode(rawImage, width, height, imageFileName);

    glGenTextures(1, &id_);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, id_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &rawImage[0]);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
    glDeleteTextures(1, &id_);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, id_);
}

void Texture::unBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
