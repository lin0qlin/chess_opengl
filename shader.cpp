#include "shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include "renderer.h"


unsigned int Shader::loadShader(const std::string& path, unsigned int type) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string code = buffer.str();
    const char* shaderCode = code.c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    return shader;
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    unsigned int vertexShader = loadShader(vertexPath, GL_VERTEX_SHADER);
    unsigned int fragmentShader = loadShader(fragmentPath, GL_FRAGMENT_SHADER);

    programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use() {
    glUseProgram(programID);
}

unsigned int Shader::GetUniformLocation(const std::string &name)
{
    if (m_UniformLocationCache.find(name)!= m_UniformLocationCache.end()){
        return m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(programID, name.c_str()));
    if (location == -1){
        std::cout<<"Warning: uniform '"<< name << "' doesn't exist!"<<std::endl;
    }
    m_UniformLocationCache[name] = location;

    return location;
}


Shader::~Shader(){
    glUseProgram(programID);
}

void Shader::Bind() const
{
    GLCall(glUseProgram(programID));
}

void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}


void Shader::setUniform3fv(const std::string &name, const glm::vec3 vector)
{
    GLCall(glUniform3fv(GetUniformLocation(name),1, &vector[0]));
}
