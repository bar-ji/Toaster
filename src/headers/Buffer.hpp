#ifndef BUFFER_H
#define BUFFER_H

class Buffer{
protected:
    GLuint ID;
public:
    virtual void Bind() = 0;
    virtual void Unbind() = 0;
    virtual void Delete() = 0;
};

#endif