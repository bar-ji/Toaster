#include "../headers/HelperFunctions.hpp"

GLFWwindow *CreateWindow(glm::vec2 windowSize)
{
    GLFWwindow *window = glfwCreateWindow(windowSize.x, windowSize.y, "Toaster", NULL, NULL);
    glfwMakeContextCurrent(window);
    return window;
}

bool InitialiseGLFW()
{
    //Initialise GLFW
    if (!glfwInit())
    {
        return false;
    }
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return true;
}

void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    int frameBufferx, framebufferY;
    glfwGetFramebufferSize(window, &frameBufferx, &framebufferY);
    glViewport(0, 0, frameBufferx, framebufferY);
}

float Clamp(float input, float maxVal, float minVal)
{
    if (input > maxVal) input = maxVal;
    if (input < minVal) input = minVal;
    return input;
}

void HandleDeltaTime(float &deltaTime, float &lastFrame)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}