#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <vector>
#include "texture.h"
#include "shader.h"


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


class Object {
public:
    static bool loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices,
                        std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals);
};

class ChessPiece {
public:
    enum PieceType { PAWN, ROOK, BISHOP, KNIGHT, QUEEN, KING };

    ChessPiece(PieceType type, bool isWhite, glm::vec3 position);
    void draw(const Shader& shader) const;
//    void setPosition(glm::vec2 position);
//    glm::vec2 getPosition() const;
    bool isValidMove(const ChessBoard& board, glm::vec2 destination) const;
    bool isWhite() const { return isWhite_; }
    PieceType getType() const { return type_; }

private:
    PieceType type_;
    bool isWhite_;
    glm::vec3 position_;
    Texture* texture_;
    std::vector<glm::vec3> vertices_;
    std::vector<glm::vec2> uvs_;
    std::vector<glm::vec3> normals_;
};


#endif // OBJECT_H

