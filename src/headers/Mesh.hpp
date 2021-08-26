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
    Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, Texture texture);

    void Draw(Shader& shader, Camera& camera);
};


#endif
