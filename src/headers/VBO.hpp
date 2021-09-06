#ifndef VBO_H
#define VBO_H

#include<glad/glad.h>
#include<glm/glm.hpp>
#include<vector>
#include"Buffer.hpp"
struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texUV;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};
class VBO : public Buffer
{
public:
    VBO(std::vector<Vertex>& vertices);

    void Bind() override;

    void Unbind() override;

    void Delete() override;
};

#endif
