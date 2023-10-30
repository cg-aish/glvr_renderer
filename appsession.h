#pragma once

#include <memory>
#include "common/customdefines.h"
#include "appwindow.h"
#include "glrenderer.h"
#include "scene.h"

namespace GLVR::Core {

    class AppSession
    {
        
    public:
        AppSession();

        void init();
        void run();
        void destroy();

        ~AppSession() = default;

    private:
        AppSession(const AppSession&) = delete;
        AppSession(const AppSession&&) = delete;
        AppSession& operator=(const AppSession&) = delete;
        AppSession& operator=(AppSession&&) = delete;

    private:
        std::string current_api = RenderAPIToString(RenderAPI::GL) ;
        GLVR::Core::AppWindow* _render_window;
        std::unique_ptr<GLVR::Renderer::GLRenderer> _gl_renderer;
        std::shared_ptr<GLVR::Core::Scene> _scene;
        struct window_data{
            void* _window_handle = nullptr;
            u32 _window_id = 0;
            u32 _window_width = 1920;
            u32 _window_height = 1080;
            std::string _window_name = "GLV Renderer";
        }_window_data;
    };
}