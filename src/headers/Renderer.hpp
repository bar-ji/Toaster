#ifndef RENDERER_H
#define RENDERER_H
#include "Model.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Light.hpp"

//Singleton Pattern
class Renderer
{
private:
    static Renderer* instance;
    Renderer(); //Private constructor therefore cannot be instantiated
public:
    static void DrawModel(Model* model, Shader& shader, Camera& camera, Light& light);
    static Renderer* GetInstance();
};

#endif