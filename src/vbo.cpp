//
// Created by micha on 1/23/2022.
//

#include "vbo.h"

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}

void VBO::bind() {
    glBindBuffer(type, id);
}

unsigned int VBO::getId() {
    return id;
}

VBO::VBO(int type, bool dynamic) {
    this->type = type;
    this->dynamic = dynamic;

    glGenBuffers(1, &id);
}

void VBO::buffer(void *data, size_t size) {
    bind();
    glBufferData(type, size, data, (dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW));
}
