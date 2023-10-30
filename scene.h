#pragma once

#include <vector>
#include <memory>

#include "primitives.h"

namespace GLVR::Core
{

    class Scene
    {

        public:
            Scene() = default;
            ~Scene() = default;



        public:
            void add_mesh(std::shared_ptr<GLVR::Mesh::Geometry> mesh);
            inline std::vector<std::shared_ptr<GLVR::Mesh::Geometry>>& get_meshes()
            {
                return _meshes;
            }

        private:
            std::vector<std::shared_ptr<GLVR::Mesh::Geometry>> _meshes;

    };

}