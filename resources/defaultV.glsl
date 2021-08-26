#version 330 core

//Position
layout (location = 0) in vec3 aPos;
//Normal
layout (location = 1) in vec3 aNormal;
//Color
layout (location = 2) in vec3 aColor;

out vec3 position;
out vec3 normal;
out vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    position = aPos;
    normal = aNormal;
    color = aColor;
}

