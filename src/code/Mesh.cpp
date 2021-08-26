#include "../headers/Mesh.hpp"

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, Texture texture)
{
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    Mesh::texture = texture;

    Mesh::position = glm::vec3();
    Mesh::scale = glm::vec3(1.0f, 1.0f, 1.0f);
    Mesh::rotation = glm::vec3(0.0f, 0.0f, 0.0f);

    vao.Bind();

    VBO vbo(vertices);
    EBO ebo(indices);

    //Position
    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)(0 * sizeof(GLfloat)));
    //Normal
    vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(GLfloat)));
    //Color
    vao.LinkAttrib(vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(GLfloat)));
    //Tex Coords
    vao.LinkAttrib(vbo, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(GLfloat)));

    vao.Unbind();
}

void Mesh::Draw(Shader& shader, Camera& camera)
{
    shader.Use();
    shader.SetMat4("projection", camera.GetProjectionMatrix());
    shader.SetMat4("view", camera.GetViewMatrix());
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, scale);
    model = glm::translate(model, position);
    shader.SetMat4("model", model);

    texture.TexUnit(shader, "texture", 0);

    vao.Bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}