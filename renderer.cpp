#include "renderer.h"

void Renderer::render(const ChessBoard& board, const std::vector<ChessPiece>& pieces) {
    board.draw();
    for (const auto& piece : pieces) {
        piece.draw();
    }
}
