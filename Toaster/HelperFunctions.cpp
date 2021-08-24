#include "HelperFunctions.hpp"

GLFWwindow* CreateWindow(glm::vec2 windowSize)
{
    GLFWwindow* window = glfwCreateWindow(windowSize.x, windowSize.y, "Toaster", NULL, NULL);
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

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return true;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

float Clamp(float input, float maxVal, float minVal)
{
    if (input > maxVal) input = maxVal;
    if (input < minVal) input = minVal;
    return input;
}