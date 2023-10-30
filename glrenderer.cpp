#include "glrenderer.h"

GLVR::Renderer::GLRenderer::GLRenderer()
{
    
}

void GLVR::Renderer::GLRenderer::init()
{
    std::cout << "Initializing GL Renderer." << std::endl;

}

void GLVR::Renderer::GLRenderer::render(std::shared_ptr<GLVR::Core::Scene>& scene)
{
    //std::cout << "GL Renderer rendering." << std::endl;
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(auto& mesh : scene->get_meshes())
    {

        glGenVertexArrays(1, mesh->get_vao());
        glBindVertexArray(mesh->get_vao()[0]);

        glCreateBuffers(1, mesh->get_vbo());
        glBindBuffer(GL_ARRAY_BUFFER, mesh->get_vbo()[0]);
        glBufferStorage(GL_ARRAY_BUFFER, mesh->get_vertices()->size() * sizeof(float), mesh->get_vertices()->data(), 0);

        _shader.setup(mesh);
        
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(mesh->get_vao()[0]);
        glDrawArrays(GL_TRIANGLES, 0, mesh->get_vertices()->size());

    }
}

void GLVR::Renderer::GLRenderer::destroy()
{
    std::cout << "Destroying GL Renderer." << std::endl;
}
