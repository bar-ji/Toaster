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
#include "../headers/Settings.hpp"
#include "../headers/Transform.hpp"


void DrawUI();

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

    Light light(glm::vec3(0.0f, 20.0f, 0.0f),  glm::vec3(1.0f, 1.0f, 1.0f));
    Shader shader("../../resources/shaders/defaultv.glsl", "../../resources/shaders/defaultf.glsl");
    Camera camera(windowSize);
    Model* backpackModel = new Model("../../resources/models/backpack/backpack.obj");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    while (!glfwWindowShouldClose(window))
    {
        //Setup
        HandleDeltaTime(deltaTime, lastFrame);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(clearDepth)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);
        if(isWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        //Input
        camera.InputHandler(window, deltaTime);
        //Drawing
        shader.SetVec3("modelColor", glm::vec3(colorOverlay[0], colorOverlay[1], colorOverlay[2]));
        Renderer::GetInstance()->DrawModel(backpackModel, shader, camera, light, Transform{glm::vec3(position[0], position[1], position[2]), glm::vec3(rotation[0], rotation[1], rotation[2]),glm::vec3(scale[0], scale[1], scale[2])});
        DrawUI();
        //Cleaning
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //Free resources
    delete backpackModel;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void DrawUI()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Modifiers");
    if(ImGui::CollapsingHeader("Controls:"))
    {
        ImGui::Text("Orbit: WASD");
        ImGui::Text("Zoom In: Left Shift");
        ImGui::Text("Zoom Out: Left Control");
    }
    if(ImGui::CollapsingHeader("Transformations:"))
    {
        ImGui::SliderFloat3("Position", position, -1.0f, 1.0f);
        ImGui::SliderFloat3("Rotation", rotation, 0.0f, 360.0f);
        ImGui::SliderFloat3("Scale", scale, 0.1f, 3.0f);
        if(ImGui::Button("Reset Position"))
        {
            for(int i = 0; i < sizeof(position) / sizeof(float); i++){
                position[i] = 0.0f;
            }
        }
        if(ImGui::Button("Reset Rotation"))
        {
            for(int i = 0; i < sizeof(rotation) / sizeof(float); i++){
                rotation[i] = 0.0f;
            }
        }
        if(ImGui::Button("Reset Scale"))
        {
            for(int i = 0; i < sizeof(scale) / sizeof(float); i++){
                scale[i] = 1.0f;
            }
        }
    }
    if(ImGui::CollapsingHeader("Colors:"))
    {
        ImGui::ColorEdit3("Hue", colorOverlay);
    }
    if(ImGui::CollapsingHeader("Rendering:"))
    {
        ImGui::Checkbox("Wireframe Mode", &isWireframe);
        ImGui::Checkbox("Depth Test", &clearDepth);
    }


    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}