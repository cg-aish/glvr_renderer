#pragma once

#include <memory>

#include "common/customdefines.h"
#include "glad/glad.h"
//#include "glad/gl.h"
#ifdef _WIN32
    #include "deps/GLFW/Win-mingw-x64/include/glfw3.h"
#elif _LINUX
    #include <glfw-3.3.8.bin.LINUX64/include/glfw3.h>
#endif

namespace GLVR::Core {
    
    class AppWindow
    {

    public:
        AppWindow(std::string current_api);

        void init(const u32 window_width, const u32 window_height, std::string window_name) noexcept;
        void show();
        void destroy();
        void setWindowContextCurrent();
        void setKeyAndMouseCallbacks();
        void setGLWindowHint(u8 major_version, u8 minor_version);
        void setGLWindowProcAddress();
        bool isRunning();
        void pollEvents();

        std::pair<u32, u32> getFrameBufferSize();
        void setViewportSize();

        f64 getCurrentTime();
        void swapBuffers();

        ~AppWindow() = default;

    private:
        AppWindow(const AppWindow&) = delete;
        AppWindow(const AppWindow&&) = delete;
        AppWindow& operator=(const AppWindow&) = delete;
        AppWindow& operator=(AppWindow&&) = delete;

    private:
        GLFWwindow* _window;
        std::string curr_api;
        
    };

}