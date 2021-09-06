#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../headers/HelperFunctions.hpp"
#include "../headers/Light.hpp"
#include "../headers/Model.hpp"
#include "../headers/Renderer.hpp"


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

    //IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    #pragma endregion


    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    Light light(glm::vec3(0.0f, 20.0f, 0.0f),  glm::vec3(1.0f, 1.0f, 1.0f));

    Shader shader("../../resources/shaders/defaultv.glsl", "../../resources/shaders/defaultf.glsl");

    Camera camera;
    camera.SetProjectionMatrix(45.0f, (float) windowSize.x / (float) windowSize.y, 0.1f,100.0f);
    Model* backpackModel = new Model("../../resources/models/backpack/backpack.obj");
    Renderer renderer;

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        HandleDeltaTime(deltaTime, lastFrame);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.InputHandler(window, deltaTime);
        renderer.DrawModel(backpackModel, shader, camera, light);
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