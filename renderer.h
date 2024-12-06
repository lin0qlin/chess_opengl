#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <signal.h>

#include "object.h"
#include "shader.h"

#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
public:
    Renderer();
    void render(const ChessBoard& board, const std::vector<ChessPiece>& pieces, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);
    void Clear() const;
};

#endif // RENDERER_H
