#include "renderer.h"
#include <iostream>

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


void Renderer::render(const ChessBoard& board, const std::vector<ChessPiece>& pieces, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
    Shader shader("shaders/SimpleVertexShader.vertexshader", "shaders/SimpleFragmentShader.fragmentshader");
    shader.use();

    // Set view and projection matrices
    unsigned int viewLoc = glGetUniformLocation(shader.programID, "view");
    unsigned int projLoc = glGetUniformLocation(shader.programID, "projection");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &viewMatrix[0][0]);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projectionMatrix[0][0]);

    // Render chessboard and pieces
    board.draw();
    for (const auto& piece : pieces) {
        piece.draw();
    }
}


void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
