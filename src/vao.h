//
// Created by micha on 1/23/2022.
//

#ifndef LEARNOPENGL_VAO_H
#define LEARNOPENGL_VAO_H

#include <glad/glad.h>
#include "vbo.h"

class VAO {
public:
    VAO();
    ~VAO();

    void bind();
    void enableAttribute(int index, int size, int stride, int offset);
    unsigned int getId();
private:
    unsigned int id;
};

#endif //LEARNOPENGL_VAO_H
