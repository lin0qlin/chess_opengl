#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <vector>


class ChessBoard {
public:
    ChessBoard();
    void draw() const;
    int getPiece(int x, int y) const;
    void setPiece(int x, int y, int piece);
    void removePiece(int x, int y);

private:
    int board[8][8];
};


class ChessPiece {
public:
    enum PieceType { PAWN, ROOK, BISHOP, KNIGHT, QUEEN, KING };

    ChessPiece(PieceType type, bool isWhite, glm::vec2 position);
    void draw() const;
    void setPosition(glm::vec2 position);
    glm::vec2 getPosition() const;
    bool isValidMove(const ChessBoard& board, glm::vec2 destination) const;
    bool isWhite() const { return isWhite_; }
    PieceType getType() const { return type_; }

private:
    PieceType type_;
    bool isWhite_;
    glm::vec2 position_;
};

#endif // OBJECT_H

