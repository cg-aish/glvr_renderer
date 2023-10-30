
#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "common/customdefines.h"

namespace GLVR::Mesh
{
    class Geometry
    {


        public:
            Geometry() = default;
            virtual ~Geometry() = default;


        public:
            inline void set_name(std::string name)
            {
                _name = name;
            }

            inline std::string get_name()
            {
                return _name;
            }

            

        public:
            virtual std::vector<float>* get_vertices() = 0;
            virtual u32* get_vao() = 0;
            virtual u32* get_vbo() = 0;
            virtual std::string& get_vertex_shader_string() = 0;
            virtual std::string& get_fragment_shader_string() = 0;
            virtual unsigned int& get_shader_program() = 0;
            virtual ShaderData& get_shader_data() = 0;
            virtual void set_shader_program(unsigned int shader_program) = 0;
            virtual inline MeshType get_geo_type() = 0;
            virtual inline PrimitiveType get_primitive_type() = 0;
            virtual bool get_is_primitive() = 0;

        private:
            std::string _name;
    };
}