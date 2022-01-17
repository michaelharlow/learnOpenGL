#version 120

in vec3 color;


void main() {
    gl_FragColor = vec4(sin(color + 1), 1.0);
}
