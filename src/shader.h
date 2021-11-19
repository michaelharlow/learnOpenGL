//
// Created by michael harlow on 11/18/2021.
//

#ifndef LEARNOPENGL_SHADER_H
#define LEARNOPENGL_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    unsigned int ID;
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

    void use();
    void setBool(const std::string &name, bool value) const;
private:
    void checkCompileErrors(GLuint shader, std::string type);
};

#endif //LEARNOPENGL_SHADER_H
