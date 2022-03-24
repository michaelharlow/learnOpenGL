//
// Created by micha on 2/22/2022.
//

#ifndef LEARNOPENGL_CUBESPHERE_H
#define LEARNOPENGL_CUBESPHERE_H

#include <array>
#include "glm/glm.hpp"
#include "vector"

struct Mesh {
    std::vector<float> vertices;
    std::vector<unsigned int> triangles;
};

class Plane {
private:
    int resolution;
    glm::vec3 localUp, axisA, axisB;
    Mesh mesh;
public:
    Plane(int resolution, glm::vec3 localUp);
    Plane();

    void constructMesh(int triangleOffset);
    const Mesh& getMesh();
};

class CubeSphere {
public:
    int resolution;
    Mesh mesh;

    CubeSphere(int resolution);

    void constructMesh();

private:
    std::array<Plane, 6> faces;

    glm::vec3 directions[6] = {
            glm::vec3(1, 0, 0),
            glm::vec3(-1, 0, 0),
            glm::vec3(0, 1, 0),
            glm::vec3(0, -1, 0),
            glm::vec3(0, 0, 1),
            glm::vec3(0, 0, -1)
    };
};


#endif //LEARNOPENGL_CUBESPHERE_H
