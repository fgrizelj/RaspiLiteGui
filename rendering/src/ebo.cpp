#include "ebo.h"

Ebo::Ebo()
{
    glGenBuffers(1, &id_);
}

Ebo::~Ebo()
{
    glDeleteBuffers(1, &id_);
}

void Ebo::setBufferData(const std::vector<GLushort>& bufferData)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferData.size() * sizeof(GLushort), &bufferData[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Ebo::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
}

void Ebo::unBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
