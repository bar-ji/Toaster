#include"../headers/VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& vbo, GLuint location, GLuint numComponentsPerVertex, GLenum type, GLuint stride, void* offset)
{
    glVertexAttribPointer(location, numComponentsPerVertex, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(location);
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