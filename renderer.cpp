#include "renderer.h"

Renderer::Renderer()
{

}

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line){
    while (GLenum error = glGetError()){
        std::cout << "[OpenGL error] " <<error<<" : "<<function<<" "<<file<<":"<<line<<std::endl;
        return false;
    }
    return true;
}

void Renderer::render(const ChessBoard& board, const std::vector<ChessPiece>& pieces, const glm::mat4& viewMatrix) {
    Shader shader("shaders/SimpleVertexShader.vertexshader", "shaders/SimpleFragmentShader.fragmentshader");
    shader.use();

    // 设置视图矩阵
    unsigned int viewLoc = glGetUniformLocation(shader.programID, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &viewMatrix[0][0]);

    // 渲染棋盘
    board.draw();

    // 渲染棋子
    for (const auto& piece : pieces) {
        piece.draw();
    }
}


void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
