
#include <iostream>
#include <memory>

#include "scene.h"
#include "primitives.h"

void GLVR::Core::Scene::add_mesh(std::shared_ptr<GLVR::Mesh::Geometry> mesh)
{

    std::cout << "Adding new geometry to the scene: " << std::endl;
    _meshes.push_back(mesh);
}
