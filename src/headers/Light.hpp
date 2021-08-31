#ifndef LIGHT_H
#define LIGHT_H
#include<glm/glm.hpp>
#include"../headers/Mesh.hpp"

class Light{
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 color;

    Mesh* mesh;
public:

    Light(glm::vec3 position, glm::vec3 rotation, glm::vec3 color);

    void SetMesh(Mesh& mesh);
    Mesh& GetMesh();

    glm::vec3 GetPosition();
    glm::vec3 GetRotation();
    glm::vec3 GetColor();

    void SetPosition(glm::vec3 position);
    void SetRotation(glm::vec3 rotation);
    void SetColor(glm::vec3 color);
};


#endif