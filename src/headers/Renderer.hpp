#ifndef RENDERER_H
#define RENDERER_H
#include "Model.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Light.hpp"

class Renderer
{
private:
    Renderer* renderer;
public:
    Renderer();
    void DrawModel(Model* model, Shader& shader, Camera& camera, Light& light);
};

#endif