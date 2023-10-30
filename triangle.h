#pragma once

#include <vector>
#include <string>
#include "common/customdefines.h"
#include "primitives.h"


namespace GLVR::Mesh
{
    class Triangle : public Geometry
    {
        public:
            Triangle()
            {
                _is_primitive = true;
                _geo_type = MeshType::TYPE_2D;
                _prim_type = PrimitiveType::Triangle;

                _triangle_shader_data.shader_program = 0;
                _triangle_shader_data.shader_data_type_and_source.push_back({ShaderType::VERTEX, _vertex_shader_string});
                _triangle_shader_data.shader_data_type_and_source.push_back({ShaderType::FRAGMENT, _fragment_shader_string});
            }
            ~Triangle() = default;

        public:
            inline std::vector<float>* get_vertices() override
            {
                return &_vertices;
            };
            inline u32* get_vao() override
            {
                return &_VAO;
            };
            inline u32* get_vbo() override
            {
                return &_VBO;
            };
            std::string& get_vertex_shader_string() override
            {
                return _vertex_shader_string;
            }
            std::string& get_fragment_shader_string() override
            {
                return _fragment_shader_string;
            }

            ShaderData& get_shader_data() override
            {
                return _triangle_shader_data;
            }

            unsigned int& get_shader_program() override
            {
                return _triangle_shader_program;
            }

            void set_shader_program(unsigned int shader_program) override
            {
                _triangle_shader_program = shader_program;
            }

            inline MeshType get_geo_type() override
            {
                return _geo_type;
            }

            inline PrimitiveType get_primitive_type() override
            {
                return _prim_type;
            }

            bool get_is_primitive() override
            {
                return _is_primitive;
            }

        private:
            bool _is_primitive = true;
            MeshType _geo_type;
            PrimitiveType _prim_type;

            std::vector<float> _vertices{
                -0.5f, -0.5f, 0.0f,
                 0.5f, -0.5f, 0.0f,
                 0.0f,  0.5f, 0.0f
            };

            u32 _VBO;
            u32 _VAO;

            unsigned int _triangle_shader_program;
            ShaderData _triangle_shader_data;

            std::string _vertex_shader_string = R"(
                #version 460 core
                layout (location = 0) in vec3 aPos;
                void main()
                {
                    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
                }
                )";

            std::string _fragment_shader_string = R"(
                #version 460 core
                out vec4 fragColor;
                void main()
                {
                    fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
                }
                )";
    };
}