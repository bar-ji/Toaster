#include"../headers/VAO.hpp"

VAO::VAO() 
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO vbo, GLuint location)
{
	vbo.Bind();
	glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(location);
	vbo.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(ID);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}