#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>
#include <vector>
#include "Buffer.hpp"

class EBO : public Buffer
{
public:
    EBO(std::vector<GLuint>& indices);

    void Bind() override;

    void Unbind() override;

    void Delete() override;
};

#endif