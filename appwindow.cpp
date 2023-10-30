#include "appwindow.h"
#include <iostream>
#include <cstdlib>

// --------------------------------- Non Member Callback functions ------------------------------------ //
static void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        std::cout << "Closing application window." << std::endl;
    }
}

static void
mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        f64 xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "Mouse clicked at --> [ X: " << xpos << " | Y: " << ypos << " ]" << std::endl;
    }
}

// --------------------------------- Non Member Callback functions ------------------------------------ //

// --------------------------------- Class Members ------------------------------------ //

GLVR::Core::AppWindow::
AppWindow(std::string current_api)
    :_window(nullptr), curr_api(current_api)
{
    if(!glfwInit())
    {
        std::cerr << "unable to initialize GLFW, check the library." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void GLVR::Core::AppWindow::
init(const u32 window_width, const u32 window_height, std::string window_name) noexcept
{
    _window = glfwCreateWindow(window_width, window_height, window_name.c_str(), nullptr, nullptr);
    if(!_window)
    {
        glfwTerminate();
        std::cerr << "Window creation failed." << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);
}

void GLVR::Core::AppWindow::
show()
{
    setWindowContextCurrent();
    setKeyAndMouseCallbacks();
    //setViewportSize();
    while (!isRunning())
    {
        pollEvents();
        std::cout << "Render window running." << std::endl;
        
    }
}

void GLVR::Core::AppWindow::
setWindowContextCurrent()
{
    glfwMakeContextCurrent(_window);
}

void GLVR::Core::AppWindow::
setKeyAndMouseCallbacks()
{
    // Set mouse and keyboard callbacks
    glfwSetKeyCallback(_window, key_callback);
    glfwSetMouseButtonCallback(_window, mouse_callback);
}

void GLVR::Core::AppWindow::
setGLWindowHint(u8 major_version, u8 minor_version)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_version);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_version);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
}

bool GLVR::Core::AppWindow::isRunning()
{
    return glfwWindowShouldClose(_window);
}

void GLVR::Core::AppWindow::
pollEvents()
{
    glfwPollEvents();
}

void GLVR::Core::AppWindow::
setGLWindowProcAddress()
{
    //gladLoadGL(glfwGetProcAddress);
    glfwMakeContextCurrent(_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    } 
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
}

void GLVR::Core::AppWindow::
destroy()
{
    std::cout << "Render window destroyed." << std::endl;
    glfwTerminate();
}

std::pair<u32, u32> GLVR::Core::AppWindow::
getFrameBufferSize()
{
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(_window, &screenWidth, &screenHeight);
    return std::pair(screenWidth, screenHeight);
}

void GLVR::Core::AppWindow::
setViewportSize()
{
    std::pair<u32 , u32> viewport_size = getFrameBufferSize();
    //glViewport(0, 0, viewport_size.first, viewport_size.second);
}

void GLVR::Core::AppWindow::
swapBuffers()
{
    
    glfwSwapBuffers(_window);
}