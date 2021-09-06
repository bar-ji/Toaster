#version 330 core

out vec4 FragColor;

in vec3 position;
in vec3 normal;
in vec2 texCoord;
in vec3 fragPos;
uniform sampler2D texture_diffuse1;

uniform vec3 lightColor;

uniform vec3 lightPos;

uniform vec3 modelColor;

void main()
{
    //Ambient Lighting
    float ambientStrength = 0.7f;
    vec3 ambient = ambientStrength * lightColor;

    //Diffuse Lighting
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * lightColor;
    vec3 result = (ambient + diffuse);
    FragColor = texture(texture_diffuse1, texCoord) * vec4(result, 1.0f) * vec4(modelColor, 1.0f);
}