
#include <iostream>
#include "common/customdefines.h"
#include "appsession.h"

#include "primitives.h"
#include "triangle.h"

GLVR::Core::AppSession::
AppSession()
    :_render_window(nullptr), _gl_renderer(nullptr), _scene(nullptr)
{
    std::cout << "Initializing application main session." << std::endl;
    std::cout << "Current platform is: " << CURRENT_PLATFORM << std::endl;
    std::cout << "Defualt render api is: " << DEFAULT_API << std::endl;
    std::cout << "Current render api is: " << current_api << std::endl;

    _render_window = new GLVR::Core::AppWindow(current_api);
    _gl_renderer = std::make_unique<GLVR::Renderer::GLRenderer>();
    _scene = std::make_shared<GLVR::Core::Scene>();
}

void GLVR::Core::AppSession::
init()
{
    _render_window->init(_window_data._window_width, _window_data._window_height, _window_data._window_name);
    _render_window->setWindowContextCurrent();
    _render_window->setKeyAndMouseCallbacks();
    _render_window->setViewportSize();

    if(current_api == RenderAPIToString(RenderAPI::GL))
    {
       _render_window->setGLWindowHint(4, 6);
       _render_window->setGLWindowProcAddress();
        _gl_renderer->init();
    }
}

void GLVR::Core::AppSession::
run()
{
    std::cout << "Running App Session" << std::endl;
    
    // Create test geometry and add into the scene
    std::shared_ptr<GLVR::Mesh::Geometry> triangle01 = std::make_shared<GLVR::Mesh::Triangle>();
    triangle01->set_name("Triangle01");
    std::cout << "Is Primitive: " << std::boolalpha << triangle01->get_is_primitive()
              << "\nRendering Primitive type: " << triangle01->get_primitive_type() 
              << "\nGeo type: " << triangle01->get_geo_type() << std::endl;

    _scene->add_mesh(triangle01);

    while(!_render_window->isRunning())
    {
        _render_window->pollEvents();
        if(current_api == RenderAPIToString(RenderAPI::GL))
        {
            _gl_renderer->render(_scene);
            _render_window->swapBuffers();
        }
    }
}

void GLVR::Core::AppSession::
destroy()
{
    _render_window->destroy();
}
