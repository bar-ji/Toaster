#include"../headers/Light.hpp"

Light::Light(glm::vec3 position, glm::vec3 rotation, glm::vec3 color)
{
    Light::position = position;
    Light::rotation = rotation;
    Light::color = color;
}

Mesh& Light::GetMesh()
{
    return *mesh;
}

glm::vec3 Light::GetPosition()
{
    return position;
}

glm::vec3 Light::GetRotation()
{
    return rotation;
}

glm::vec3 Light::GetColor()
{
   return color;
}

void Light::SetMesh(Mesh& mesh)
{
    Light::mesh = &mesh;
}

void Light::SetPosition(glm::vec3 position)
{
    Light::position = position;
}

void Light::SetRotation(glm::vec3 rotation)
{
    Light::rotation = rotation;
}

void Light::SetColor(glm::vec3 color)
{
    Light::color = color;
}