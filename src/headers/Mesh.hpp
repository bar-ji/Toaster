#ifndef MESH_H
#define MESH_H

#include <string>
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"
#include "Texture.hpp"

class Mesh
{
private :
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    Texture texture;

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;

    VAO vao;
public:
    Mesh(std::vector <Vertex> vertices, std::vector <GLuint> indices, Texture texture);
    void Draw(Shader& shader, Camera& camera);

    glm::vec3 GetPosition();
    glm::vec3 GetRotation();
    glm::vec3 GetScale();

    void SetPosition(glm::vec3 position);
    void SetRotation(glm::vec3 rotation);
    void SetScale(glm::vec3 scale);
};




#endif
