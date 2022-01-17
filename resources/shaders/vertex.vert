#version 330

layout (location = 0) in vec3 aPos;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

out vec3 color;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    color = aPos;
}