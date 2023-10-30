#pragma once

#include <memory>

#include "glad/glad.h"
#include "common/customdefines.h"
#include "primitives.h"

namespace GLVR::Core
{

    class Shader
    {
        public:
            Shader() = default;
            ~Shader() = default;

        public:
            void setup(std::shared_ptr<GLVR::Mesh::Geometry> mesh);
            void shader_compile_success(u32 &shader, ShaderType type);
            void cleanup();
    };
}