#include"../headers/Light.hpp"

Light::Light(glm::vec3 position, glm::vec3 color)
{
    Light::position = position;
    Light::color = color;
}

glm::vec3 Light::GetPosition()
{
    return position;
}

glm::vec3 Light::GetColor()
{
   return color;
}

void Light::SetPosition(glm::vec3 position)
{
    Light::position = position;
}

void Light::SetColor(glm::vec3 color)
{
    Light::color = color;
}