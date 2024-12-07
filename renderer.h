#ifndef RENDERER_H
#define RENDERER_H

#include "object.h"
#include <vector>

class Renderer {
public:
    void render(const ChessBoard& board, const std::vector<ChessPiece>& pieces);
};

#endif // RENDERER_H
