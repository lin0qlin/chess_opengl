#include "renderer.h"
#include "shader.h"

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

void Renderer::render(const ChessBoard& board, const std::vector<ChessPiece>& pieces) {
    board.draw();
    for (const auto& piece : pieces) {
        piece.draw();
    }
}

void Renderer::Clear() const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
