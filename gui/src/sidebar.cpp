#include "sidebar.h"
#include <numeric>

Sidebar::Sidebar()
{
    Vbo::VertexAttribPointer verticesPointer = {3, 0, 0};
    std::vector<Vbo::VertexAttribPointer> vertexPointers;
    vertexPointers.push_back(verticesPointer);
    
    vbo_.setBufferData(getVertices());
    vbo_.setVertexAttribPointers(vertexPointers);

    auto indices = getIndices();
    indicesSize_ = indices.size();
    ebo_.setBufferData(indices);
}

void Sidebar::render()
{
    vbo_.bind();
    ebo_.bind();
    glDrawElements(GL_LINES, indicesSize_, GL_UNSIGNED_SHORT, 0);
}

std::vector<GLfloat> Sidebar::getVertices()
{
    std::vector<GLfloat> vertices;

    for(int i = 0; i <= 50; i++)
    {
        float factor = interpolationFactor(0, itemCount_, i);
        float interpolation = lerp(0.99f, -0.99f, factor);
        vertices.push_back(-1.0f);
        vertices.push_back(interpolation);
        vertices.push_back(0.0f);
        vertices.push_back(-0.7f);
        vertices.push_back(interpolation);
        vertices.push_back(0.0f);
    }

    return vertices;
}

std::vector<GLushort> Sidebar::getIndices()
{
    std::vector<GLushort> indices((itemCount_ + 1) * 2);
    std::iota(indices.begin(), indices.end(), 0);

    //add indices for the two vertical lines as well
    GLushort lastIndex = indices.end()[-1];
    GLushort preLastIndex = indices.end()[-2];
    indices.push_back(0);
    indices.push_back(preLastIndex);
    indices.push_back(1);
    indices.push_back(lastIndex);

    return indices;
}

float Sidebar::lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

float Sidebar::interpolationFactor(float a, float b, float lerp)
{
    return (lerp - a) / (b - a);
}
