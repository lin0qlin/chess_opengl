#ifndef RENDERER_H
#define RENDERER_H

#include "object.h"
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include <signal.h>

#define ASSERT(x) if (!(x)) raise(SIGTRAP);
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
public:
    Renderer();
    void render(const ChessBoard& board, const std::vector<ChessPiece>& pieces);
    void Clear() const;
};

#endif // RENDERER_H
