#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include "VBO.hpp"

class VAO
{
private:
    GLuint ID;
public:
    VAO();

    void LinkAttrib(VBO& vbo, GLuint location, GLuint numComponentsPerVertex, GLenum type, GLuint stride, void* offset);

    void Bind();

    void Unbind();

    void Delete();
};

#endif
