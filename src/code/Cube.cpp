#include "../headers/Cube.hpp"

Cube::Cube() : shader("resources/cubev.glsl", "resources/cubef.glsl")
{
    std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
    vao.Bind();
    VBO vbo(verts);
    EBO ebo(ind);
    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
    vbo.Unbind();
    vao.Unbind();

    model = glm::mat4(1.0f);
    Cube::position = glm::vec3(0.0f, 0.0f, 0.0f);
    Cube::rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    Cube::scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

void Cube::Draw(glm::mat4 view, glm::mat4 projection)
{
    shader.Use();

    shader.SetMat4("projection", projection);
    shader.SetMat4("view", view);

    model = glm::mat4(1.0f);
    model = glm::scale(model, scale);
    model = glm::translate(model, position);
    shader.SetMat4("model", model);

    vao.Bind();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

glm::mat4 Cube::GetModel()
{
    return model;
}

glm::vec3 Cube::GetPosition()
{
    return position;
}

void Cube::SetPosition(glm::vec3 position)
{
    Cube::position = position;
}