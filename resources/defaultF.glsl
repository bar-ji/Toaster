#version 330 core

out vec4 FragColor;

in vec3 position;
in vec3 normal;
in vec3 color;

void main()
{
    FragColor = vec4(color, 1.0);
}