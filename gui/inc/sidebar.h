#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <vector>
#include "GLES2/gl2.h"
#include "vbo.h"
#include "ebo.h"

class Sidebar
{
    public:
        Sidebar();

        void render();

    private:
        std::vector<GLfloat> getVertices();
        std::vector<GLushort> getIndices();
        float lerp(float a, float b, float t);
        float interpolationFactor(float a, float b, float t);

        Vbo vbo_;
        Ebo ebo_;
        int indicesSize_;
        const int itemCount_{50};
};

#endif
