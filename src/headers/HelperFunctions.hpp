#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

GLFWwindow *CreateWindow(glm::vec2 windowSize);

bool InitialiseGLFW();

void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

float Clamp(float input, float maxVal, float minVal);

#endif