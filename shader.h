#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>
#include <iostream>
#include <unordered_map>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    unsigned int programID;

    ~Shader();

    void Bind() const;
    void Unbind() const;

    void setUniform3fv(const std::string& name, const glm::vec3 vector);

private:
    unsigned int loadShader(const std::string& path, unsigned int type);
    unsigned int GetUniformLocation(const std::string &name);
    std::unordered_map<std::string, int> m_UniformLocationCache;
};

#endif // SHADER_H

