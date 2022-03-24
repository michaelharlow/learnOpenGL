//
// Created by micha on 2/22/2022.
//

#include "CubeSphere.h"

Plane::Plane(int resolution, glm::vec3 localUp) {
    this->resolution = resolution;
    this->localUp = localUp;

    axisA = glm::vec3(localUp.y, localUp.z, localUp.x);
    axisB = glm::cross(localUp, axisA);
}
Plane::Plane() {
    this->resolution = 0;
    this->localUp = glm::vec3(0);
}


void Plane::constructMesh(int triangleOffset) {
    mesh.vertices.clear();
    mesh.triangles.clear();
    int triIndex = 0;

    for (int y = 0; y < resolution; ++y) {
        for (int x = 0; x < resolution; ++x) {
            int i = x + y * resolution;
            glm::vec2 percent = glm::vec2(x, y) / (float) (resolution - 1);
            glm::vec3 pointOnUnitCube = localUp + (percent.x - .5f) * 2 * axisA + (percent.y - .5f) * 2 * axisB;
            glm::vec3 pointOnUnitSphere = glm::normalize(pointOnUnitCube);
            mesh.vertices.push_back(pointOnUnitSphere.x);
            mesh.vertices.push_back(pointOnUnitSphere.y);
            mesh.vertices.push_back(pointOnUnitSphere.z);

            if ((x != resolution - 1) && (y != resolution -1)) {
                mesh.triangles.push_back(i + triangleOffset);
                mesh.triangles.push_back(i + resolution + 1 + triangleOffset);
                mesh.triangles.push_back(i + resolution + triangleOffset);

                mesh.triangles.push_back(i + triangleOffset);
                mesh.triangles.push_back(i + 1 + triangleOffset);
                mesh.triangles.push_back(i + resolution + 1 + triangleOffset);
                triIndex += 6;
            }

        }
    }
}

const Mesh &Plane::getMesh() {
    return mesh;
}

CubeSphere::CubeSphere(int resolution) {
    for (int i = 0; i < 6; ++i) {
        faces[i] = Plane(resolution, directions[i]);
        faces[i].constructMesh(i * resolution * resolution);
    }
}

void CubeSphere::constructMesh() {
    for (int i = 0; i < faces.size(); ++i) {
        mesh.vertices.insert(mesh.vertices.end(), faces[i].getMesh().vertices.begin(), faces[i].getMesh().vertices.end());
        mesh.triangles.insert(mesh.triangles.end(), faces[i].getMesh().triangles.begin(), faces[i].getMesh().triangles.end());
    }
}
