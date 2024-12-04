#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <vector>

// 棋盘类
class ChessBoard {
public:
    ChessBoard();
    void draw() const;
    int getPiece(int x, int y) const; // 获取某格子的棋子类型
    void setPiece(int x, int y, int piece); // 设置棋子到某格子
    void removePiece(int x, int y); // 从棋盘移除某个棋子

private:
    int board[8][8]; // 棋盘状态
};


class Object {
public:
    static bool loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices,
                        std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals);
};


// 棋子类
class ChessPiece {
public:
    enum PieceType { PAWN, ROOK, BISHOP, KNIGHT, QUEEN, KING };

    ChessPiece(PieceType type, bool isWhite, glm::vec3 position);
    void draw() const;
//    void setPosition(glm::vec2 position);
//    glm::vec2 getPosition() const;
    bool isValidMove(const ChessBoard& board, glm::vec2 destination) const; // 检查合法移动
    bool isWhite() const { return isWhite_; }
    PieceType getType() const { return type_; }

private:
    PieceType type_;
    bool isWhite_;
    glm::vec3 position_;
    std::vector<glm::vec3> vertices_;
    std::vector<glm::vec2> uvs_;
    std::vector<glm::vec3> normals_;
};


#endif // OBJECT_H

