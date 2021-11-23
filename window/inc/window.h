#ifndef WINDOW_H
#define WINDOW_H

#include "EGL/egl.h"

class Window
{
    public:
        Window();
        ~Window();
        Window& operator=(const Window& other) = delete;
        Window(const Window& other) = delete;

        const EGLDisplay& getDisplay();
        const EGLSurface& getSurface();

    private:
        EGLDisplay display_;
        EGLContext context_;
        uint32_t screen_width_;
        uint32_t screen_height_;
        DISPMANX_DISPLAY_HANDLE_T dispman_display_;
        DISPMANX_ELEMENT_HANDLE_T dispman_element_;
        EGL_DISPMANX_WINDOW_T native_window_;
        EGLSurface surface_;
};

#endif
