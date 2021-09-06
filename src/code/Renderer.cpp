#include "../headers/Renderer.hpp"

Renderer::Renderer(){}

void Renderer::DrawModel(Model *model, Shader &shader, Camera &camera, Light& light, Transform transform)
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(transform.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(transform.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    modelMatrix = glm::scale(modelMatrix, transform.scale);
    modelMatrix = glm::translate(modelMatrix, transform.position);
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

Renderer* Renderer::instance = 0;

Renderer* Renderer::GetInstance()
{
    if(instance == 0)
    {
        instance = new Renderer();
    }
    return instance;
}