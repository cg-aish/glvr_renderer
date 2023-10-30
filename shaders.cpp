#include "shaders.h"

void GLVR::Core::Shader::setup(std::shared_ptr<GLVR::Mesh::Geometry> mesh)
{
    std::cout << "Setting up shader for the mesh" << std::endl;
    int success;
    char info_log[512];
    ShaderData shader_data = mesh->get_shader_data();
    GLuint* vertex_shader = nullptr;
    GLuint* fragment_shader = nullptr;
    std::vector<unsigned int> shaders;
    for(const auto& shader: shader_data.shader_data_type_and_source)
    {
        std::string shader_source_string = shader.second;
        const char* source = shader_source_string.c_str();
        switch (shader.first)
        {
        case ShaderType::VERTEX:
            vertex_shader = new GLuint(0);
            *vertex_shader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(*vertex_shader, 1, &source, NULL);
            glCompileShader(*vertex_shader);
            shader_compile_success(*vertex_shader, ShaderType::VERTEX);
            shaders.push_back(*vertex_shader);
            delete vertex_shader;
            break;
        case ShaderType::FRAGMENT:
            fragment_shader = new GLuint(0);
            *fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(*fragment_shader, 1, &source, NULL);
            glCompileShader(*fragment_shader);
            shader_compile_success(*fragment_shader, ShaderType::VERTEX);
            shaders.push_back(*fragment_shader);
            delete fragment_shader;
            break;
        default:
            break;
        }
    }

    mesh->set_shader_program(glCreateProgram());
    for(const auto& shader: shaders)
    {
        glAttachShader(mesh->get_shader_program(), shader);
        glDeleteShader(shader);
    }

    glLinkProgram(mesh->get_shader_program());
    glGetProgramiv(mesh->get_shader_program(), GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(mesh->get_shader_program(), 512, NULL, info_log);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING::FAILED\n" << info_log << std::endl;
        throw;
    }

    glUseProgram(mesh->get_shader_program());
}

void GLVR::Core::Shader::cleanup()
{
}

void GLVR::Core::Shader::shader_compile_success(u32 &shader, ShaderType type)
{
    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        std::cerr << "ERROR::SHADER::" << ShaderTypesToString(type) << "::COMPILING::FAILED\n" << info_log << std::endl;
        throw;
    }
}
