#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../headers/HelperFunctions.hpp"
#include "../headers/Mesh.hpp"
#include "../headers/Light.hpp"
#include "../headers/Camera.hpp"

const Vertex vertices[] = {
        //Top Positions
        Vertex{glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0f, 0.0f)},
        Vertex{glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2(0.0f, 1.0f)},
        Vertex{glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0f, 1.0f)},
        Vertex{glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, -1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2(1.0f, 0.0f)},

        //Bottom Positions
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2()},
        Vertex{glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2()},
        Vertex{glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2()},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(1.0, 1.0, 1.0), glm::vec2()},
        };
const GLuint indices[]{
    //Top
    0, 1, 2,
    2, 3, 0,

    //Bottom
    4, 5, 6,
    6, 7, 4,

    //Right
    2, 3, 7,
    7, 6, 2,

    //Left
    0, 1, 5,
    5, 4, 0,

    //Front
    1, 2, 6,
    6, 5, 1,

    //Back
    0, 3, 7,
    7, 4, 0
};


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

    std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<GLuint> inds(indices, indices + sizeof(indices) / sizeof(GLuint));
    Texture texture("../../resources/textures/wall.jpg");

    Light light(glm::vec3(0.0f, 20.0f, 0.0f),  glm::vec3(1.0f, 1.0f, 1.0f));

    Mesh cube(verts, inds, texture);
    cube.SetScale(glm::vec3(0.5f, 0.5f, 0.5f));
    Shader cubeShader("../../resources/shaders/defaultv.glsl", "../../resources/shaders/defaultf.glsl");
    cubeShader.Use();
    cubeShader.SetVec3("lightColor", light.GetColor());
    cubeShader.SetVec3("lightPos", light.GetPosition());

    Camera camera;
    camera.SetProjectionMatrix(45.0f, (float) windowSize.x / (float) windowSize.y, 0.1f,100.0f);

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        HandleDeltaTime(deltaTime, lastFrame);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.InputHandler(window, deltaTime);
        cube.Draw(cubeShader, camera);
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