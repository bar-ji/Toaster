#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.hpp"

class Texture
{
private:
    GLuint ID;
    GLenum type;
public:
    Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    Texture();

    void TexUnit(Shader shader, const char *uniform, GLuint unit);

    void Bind();

    void Unbind();

    void Delete();
};

#endif
