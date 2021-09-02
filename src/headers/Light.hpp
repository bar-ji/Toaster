#ifndef LIGHT_H
#define LIGHT_H
#include<glm/glm.hpp>
#include"../headers/Mesh.hpp"

class Light{
private:
    glm::vec3 position;
    glm::vec3 color;
public:

    Light(glm::vec3 position, glm::vec3 color);

    glm::vec3 GetPosition();
    glm::vec3 GetColor();

    void SetPosition(glm::vec3 position);
    void SetColor(glm::vec3 color);
};


#endif