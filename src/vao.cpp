//
// Created by micha on 1/23/2022.
//

#include "vao.h"

VAO::VAO() {
    glGenVertexArrays(1, &id);
    bind();
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);
}

void VAO::bind() {
    glBindVertexArray(id);
}

unsigned int VAO::getId() {
    return id;
}

void VAO::enableAttribute(int index, int size, int stride, int offset) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*) (offset * sizeof(float))); //0 * sizeof(float) shows that its tightly packed : could just be 0
    glEnableVertexAttribArray(0);
}

