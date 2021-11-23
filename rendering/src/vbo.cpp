#include "vbo.h"

Vbo::Vbo()
{
    glGenBuffers(1, &id_);
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &id_);
}

void Vbo::setBufferData(const std::vector<GLfloat>& bufferData)
{
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    glBufferData(GL_ARRAY_BUFFER, bufferData.size() * sizeof(GLfloat), &bufferData[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vbo::setVertexAttribPointers(const std::vector<VertexAttribPointer> vertexAttribPointers)
{
    vertexAttribPointers_ = vertexAttribPointers;
}

void Vbo::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    
    for(int i = 0; i < vertexAttribPointers_.size();i++)
    {
        glVertexAttribPointer(i, vertexAttribPointers_[i].size, GL_FLOAT, GL_FALSE, vertexAttribPointers_[i].stride, (GLvoid*)vertexAttribPointers_[i].position);
        glEnableVertexAttribArray(0);
    }
}

void Vbo::unBind()
{   
    for(int i = 0; i < vertexAttribPointers_.size();i++)
    {
        glDisableVertexAttribArray(0);
    }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
