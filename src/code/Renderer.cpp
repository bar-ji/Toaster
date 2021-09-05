#include "../headers/Renderer.hpp"

Renderer::Renderer()
{
    renderer = this;
}

void Renderer::DrawModel(Model *model, Shader &shader, Camera &camera, Light& light)
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::scale(modelMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 projectionMatrix = camera.GetProjectionMatrix();
    glm::mat4 viewMatrix = camera.GetViewMatrix();

    shader.Use();
    shader.SetMat4("model", modelMatrix);
    shader.SetMat4("view", viewMatrix);
    shader.SetMat4("projection", projectionMatrix);
    shader.SetVec3("lightColor", light.GetColor());
    shader.SetVec3("lightPos", light.GetPosition());

    model->Draw(shader);
}