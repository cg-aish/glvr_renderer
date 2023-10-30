#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

#include "appwindow.h"
#include "scene.h"
#include "shaders.h"

namespace GLVR::Renderer
{

    class GLRenderer
    {

        public:
            GLRenderer();
            ~GLRenderer() = default;

            void init();
            void render(std::shared_ptr<GLVR::Core::Scene>& scene);
            void destroy();

            void generate_and_bind_buffers();
            void compile_shader(u32& shader, ShaderType type, const char* shader_string);
            void attach_and_link_shader_program(u32 &vertex_shader, u32 &fragment_shader);
            void shader_compile_success(u32& shader_source, ShaderType type);

        private:
            std::unordered_map<std::string, GLuint> _status =
            {
                { "Compile", GL_COMPILE_STATUS },
                { "Link", GL_LINK_STATUS }
            };

            ShaderData _shader_data;
            GLVR::Core::Shader _shader;

    };

}