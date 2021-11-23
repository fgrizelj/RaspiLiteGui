#ifndef GUI_H
#define GUI_H

#include "sidebar.h"

class Gui
{
    public:
        void render();
        bool shouldUpdate();
        bool shouldExit();

    private:
        Sidebar sidebar_;
};

#endif
