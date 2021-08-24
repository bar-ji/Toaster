#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "HelperFunctions.hpp"
#include "Cube.hpp"
#include "Camera.hpp"

void HandleDeltaTime(float& deltaTime, float& lastFrame);

int main(void)
{
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    #pragma region Library Setup

    if(!InitialiseGLFW())
    {
        std::cout << "GLFW failed to initialise." << std::endl;
        return -1;
    }

    //Create a window
    glm::vec2 windowSize = glm::vec2(1920, 1080);
    GLFWwindow* window = CreateWindow(windowSize);

    if (!window)
    {
        glfwTerminate();
        std::cout << "Window failed to initialise..." << std::endl;
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD failed to load..." << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    #pragma endregion

    glViewport(0, 0, windowSize.x, windowSize.y);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Cube cube1;
    Camera camera;

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)windowSize.x / (float)windowSize.y, 0.1f, 100.0f);

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        HandleDeltaTime(deltaTime, lastFrame);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cube1.Draw(camera.GetViewMatrix(), projection);
        camera.InputHandler(window, deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void HandleDeltaTime(float& deltaTime, float& lastFrame)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}