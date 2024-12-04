#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>

class Texture {
public:
    Texture(const std::string& path);
    ~Texture();

    void Bind(unsigned int slot = 0) const; // 绑定到指定的纹理槽
    void Unbind() const;

private:
    GLuint m_RendererID; // OpenGL 纹理 ID
    std::string m_FilePath; // 纹理文件路径
    unsigned char* m_LocalBuffer; // 纹理数据
    int m_Width, m_Height, m_BPP; // 宽度、高度、每像素位数
};

#endif // TEXTURE_H

