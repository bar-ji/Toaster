#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../headers/HelperFunctions.hpp"
#include "../headers/Mesh.hpp"
#include "../headers/Light.hpp"
#include "../headers/Camera.hpp"
#include "../headers/Model.hpp"
#include "../headers/Shader.hpp"


void HandleDeltaTime(float &deltaTime, float &lastFrame);

int main()
{
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    #pragma region Library Setup

    if (!InitialiseGLFW())
    {
        std::cout << "GLFW failed to initialise." << std::endl;
        return -1;
    }

    //Create a window
    glm::vec2 windowSize = glm::vec2(1280, 720);
    GLFWwindow *window = CreateWindow(windowSize);

    if (!window)
    {
        glfwTerminate();
        std::cout << "Window failed to initialise..." << std::endl;
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "GLAD failed to load..." << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
    int frameBufferx, framebufferY;
    glfwGetFramebufferSize(window, &frameBufferx, &framebufferY);
    glViewport(0, 0, frameBufferx, framebufferY);
    #pragma endregion


    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Light light(glm::vec3(0.0f, 20.0f, 0.0f),  glm::vec3(1.0f, 1.0f, 1.0f));

    Shader cubeShader("../../resources/shaders/defaultv.glsl", "../../resources/shaders/defaultf.glsl");
    cubeShader.Use();
    cubeShader.SetVec3("lightColor", light.GetColor());
    cubeShader.SetVec3("lightPos", light.GetPosition());

    Camera camera;
    camera.SetProjectionMatrix(45.0f, (float) windowSize.x / (float) windowSize.y, 0.1f,100.0f);

    Model backpackModel("../../resources/models/backpack/backpack.obj");

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        HandleDeltaTime(deltaTime, lastFrame);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.InputHandler(window, deltaTime);
        glm::mat4 view = camera.GetViewMatrix();
        glm::mat4 projection = camera.GetProjectionMatrix();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        cubeShader.SetMat4("model", model);
        cubeShader.SetMat4("view", view);
        cubeShader.SetMat4("projection", projection);
        backpackModel.Draw(cubeShader);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void HandleDeltaTime(float &deltaTime, float &lastFrame)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}