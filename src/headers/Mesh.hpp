#ifndef MESH_H
#define MESH_H

#include <string>
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"
#include "Shader.hpp"

struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh
{
private :
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    VAO vao;
public:
    Mesh(std::vector <Vertex> vertices, std::vector <GLuint> indices, std::vector<Texture> textures);
    void Draw(Shader& shader);

    glm::vec3 GetPosition();
    glm::vec3 GetRotation();
    glm::vec3 GetScale();

    void SetPosition(glm::vec3 position);
    void SetRotation(glm::vec3 rotation);
    void SetScale(glm::vec3 scale);
};




#endif
