#version 330 core

out vec4 FragColor;

in vec3 position;
in vec3 normal;
in vec3 color;
in vec2 texCoord;
in vec3 fragPos;
uniform sampler2D ourTexture;

uniform vec3 lightColor;

uniform vec3 lightPos;

void main()
{
    //Ambient Lighting
    float ambientStrength = 0.2f;
    vec3 ambient = ambientStrength * lightColor;

    //Diffuse Lighting
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * lightColor;
    vec3 result = (ambient + diffuse);
    FragColor = texture(ourTexture, texCoord) * vec4(result, 1.0f);
}