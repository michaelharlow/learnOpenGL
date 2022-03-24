//
// Created by micha on 1/23/2022.
//

#ifndef LEARNOPENGL_VBO_H
#define LEARNOPENGL_VBO_H

#include <glad/glad.h>
#include <vector>
#include "glm/vec3.hpp"

class VBO {
public:
    VBO(int type, bool dynamic);
    ~VBO();

    void buffer(void *data, size_t size);
    void bind();
    unsigned int getId();

private:
    unsigned int id;
    int type;
    bool dynamic;
};


#endif //LEARNOPENGL_VBO_H
