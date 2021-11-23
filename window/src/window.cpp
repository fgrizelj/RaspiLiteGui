#include "window.h"
#include "bcm_host.h"
#include "GLES2/gl2.h"

Window::Window()
{
	bcm_host_init();

    display_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(display_, NULL, NULL);

	EGLConfig config;

	EGLint num_config;

	EGLint attributes[]
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, 8,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_NONE
	};

	eglChooseConfig(display_, attributes, &config, 1, &num_config);

    eglBindAPI(EGL_OPENGL_ES_API);

    EGLint context_attributes[]
    {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    context_ = eglCreateContext(display_, config, EGL_NO_CONTEXT, context_attributes);

    graphics_get_display_size(0, &screen_width_, &screen_height_);

    dispman_display_ = vc_dispmanx_display_open(0);

    DISPMANX_UPDATE_HANDLE_T dispman_update = vc_dispmanx_update_start(0);

    VC_RECT_T dst_rect;
    VC_RECT_T src_rect;
    vc_dispmanx_rect_set(&src_rect, 0, 0, screen_width_ << 16, screen_height_ <<16);
    vc_dispmanx_rect_set(&dst_rect, 0, 0, screen_width_, screen_height_);

    dispman_element_ = vc_dispmanx_element_add(dispman_update, dispman_display_, 3, &dst_rect, 0, &src_rect, DISPMANX_PROTECTION_NONE, 0, 0, DISPMANX_NO_ROTATE);

    native_window_.element = dispman_element_;
    native_window_.width = screen_width_;
    native_window_.height = screen_height_;

    vc_dispmanx_update_submit_sync(dispman_update);

    surface_ = eglCreateWindowSurface(display_, config, &native_window_, NULL);

    eglMakeCurrent(display_, surface_, surface_, context_);
}

Window::~Window()
{
    eglDestroySurface(display_, surface_);
    DISPMANX_UPDATE_HANDLE_T dispman_update = vc_dispmanx_update_start(0);
    vc_dispmanx_element_remove(dispman_update, dispman_element_);
    vc_dispmanx_update_submit_sync(dispman_update);
    vc_dispmanx_display_close(dispman_display_);
    eglMakeCurrent(display_, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroyContext(display_, context_);
    eglTerminate(display_);
}

const EGLDisplay& Window::getDisplay()
{
    return display_;
}

const EGLSurface& Window::getSurface()
{
    return surface_;
}
