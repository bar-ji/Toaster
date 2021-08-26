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
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    glm::mat4 model;

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;

    VAO vao;

    Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices);

    void Draw(Shader& shader, Camera& camera, glm::mat4 projection);
};


#endif
