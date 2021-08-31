#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.hpp"

class Texture
{
private:
    GLuint ID;
    GLuint texture;
public:
    Texture(const char* filePath);
    Texture();

    void Bind();
};

#endif
