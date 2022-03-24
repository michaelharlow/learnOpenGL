#version 330

out vec4 FragColor;

//in vec2 TexCoord;
in vec3 Color;

uniform sampler2D texture1;
uniform vec3 color;

void main() {
    //FragColor = 1 - ((texture(texture1, TexCoord).r + texture(texture1, TexCoord).b + texture(texture1, TexCoord).g) / 3) * vec4(Color + 1, 1.0);
    //FragColor = vec4(Color + 0.5, 1.0);
    FragColor = vec4(color, 1.0);
}
