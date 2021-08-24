#ifndef CUBE_H
#define CUBE_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glad/glad.h>
#include"Shader.hpp"
#include"VAO.hpp"
#include"VBO.hpp"
#include"EBO.hpp"

class Cube
{
private:
	VAO vao;
	GLfloat vertices[24] = {
		 //Top
		 -0.5f, 0.5f, -0.5f,
		 -0.5f, 0.5f, 0.5f,
		  0.5f, 0.5f, 0.5f,
		  0.5f, 0.5f, -0.5f,

		 //Bottom
		 -0.5f, -0.5f, -0.5f,
		 -0.5f, -0.5f,  0.5f,
		  0.5f, -0.5f,  0.5f,
		  0.5f, -0.5f, -0.5f,
	};
	GLuint indices[36]{
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

	glm::mat4 model{};
	glm::vec3 position{};
	glm::vec3 rotation{};
	glm::vec3 scale{};

	Shader shader;

public:
	Cube();
	void Draw(glm::mat4 view, glm::mat4 projection);
	glm::mat4 GetModel();
	glm::vec3 GetPosition();

	void SetPosition(glm::vec3 position);
};

#endif