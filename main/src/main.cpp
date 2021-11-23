#include <thread>
#include <chrono>
#include "gui.h"
#include "window.h"

int main(void)
{
    Window window;

    Gui gui;

    while(!gui.shouldExit())
    {
        if(gui.shouldUpdate())
        {
            glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
            glClear(GL_COLOR_BUFFER_BIT);
            gui.render();
            eglSwapBuffers(window.getDisplay(), window.getSurface());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
