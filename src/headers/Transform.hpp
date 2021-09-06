#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "glm/glm.hpp"
struct Transform
{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
#endif