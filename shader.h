#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();

private:
    unsigned int programID;
    unsigned int loadShader(const std::string& path, unsigned int type);
};

#endif // SHADER_H

