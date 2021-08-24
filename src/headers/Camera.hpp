#ifndef CAMERA_H
#define CAMERA_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "HelperFunctions.hpp"

class Camera
{
private:
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 rotation;

	float zoom = 10.0f;

public:
	Camera(glm::vec3 position, glm::vec3 forward, glm::vec3 up, glm::vec3 rotation);
	Camera();
	glm::mat4 GetViewMatrix();
	glm::vec3 GetCameraPos();
	glm::vec3 GetCameraForward();
	glm::vec3 GetCameraUp();
	glm::vec3 GetRotation();
	float GetZoom();
	void SetCameraPos(glm::vec3 position);
	void SetCameraForward(glm::vec3 forward);
	void SetCameraUp(glm::vec3 up);
	void SetRotation(glm::vec3 rotation);

	void InputHandler(GLFWwindow* window, float deltaTime);
};
#endif