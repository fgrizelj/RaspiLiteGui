#include "gui.h"
#include "shader.h"

void Gui::render()
{
    Shader shader {"./rendering/shaders/default.vert", "./rendering/shaders/default.frag"};
    shader.useProgram();
    sidebar_.render();
}

bool Gui::shouldUpdate()
{
    return true;
}

bool Gui::shouldExit()
{
    return false;
}
