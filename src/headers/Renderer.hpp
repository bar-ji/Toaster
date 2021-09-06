#ifndef RENDERER_H
#define RENDERER_H
#include "Model.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Transform.hpp"

//Singleton Pattern (Could also be modified to be fully static. I want to demonstrate a singleton though)
class Renderer
{
private:
    static Renderer* instance;
    Renderer(); //Private constructor therefore cannot be instantiated
public:
    static void DrawModel(Model* model, Shader& shader, Camera& camera, Light& light, Transform transform);
    static Renderer* GetInstance();
};

#endif