#include "object.h"
#include <GL/glew.h>
#include <glm/gtx/transform.hpp>
#include <iostream>

// initialize
ChessBoard::ChessBoard() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            board[x][y] = 0; // 初始化为空
        }
    }
}

int ChessBoard::getPiece(int x, int y) const {
    return board[x][y];
}

void ChessBoard::setPiece(int x, int y, int piece) {
    board[x][y] = piece;
}

void ChessBoard::removePiece(int x, int y) {
    board[x][y] = 0;
}


// ChessBoard: dessin 8*8
void ChessBoard::draw() const {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            bool isWhite = (x + y) % 2 == 0;
            glm::vec3 color = isWhite ? glm::vec3(1.0f, 1.0f, 1.0f) : glm::vec3(0.2f, 0.2f, 0.2f);
            glColor3f(color.r, color.g, color.b);

            glBegin(GL_QUADS);
            glVertex3f(x, y, 0);
            glVertex3f(x + 1, y, 0);
            glVertex3f(x + 1, y + 1, 0);
            glVertex3f(x, y + 1, 0);
            glEnd();
        }
    }
}

// ChessPiece
ChessPiece::ChessPiece(PieceType type, bool isWhite, glm::vec2 position)
    : type_(type), isWhite_(isWhite), position_(position) {
    position.x = glm::clamp(position.x, 0.0f, 7.0f);
    position.y = glm::clamp(position.y, 0.0f, 7.0f);
}


void ChessPiece::draw() const {
    std::cout << "Drawing piece at position: " << position_.x << ", " << position_.y << std::endl;
    glm::vec3 color = isWhite_ ? glm::vec3(1.0f, 0.8f, 0.6f) : glm::vec3(0.1f, 0.1f, 0.1f);
    glColor3f(color.r, color.g, color.b);

    glPushMatrix();
    glTranslatef(position_.x + 0.5f, position_.y + 0.5f, 0);

    glBegin(GL_TRIANGLES); // simple triangles
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glPopMatrix();
}

void ChessPiece::setPosition(glm::vec2 position) {
    position_ = position;
}

glm::vec2 ChessPiece::getPosition() const {
    return position_;
}



// rules of movement
bool ChessPiece::isValidMove(const ChessBoard& board, glm::vec2 destination) const {
    int dx = destination.x - position_.x;
    int dy = destination.y - position_.y;


    if (destination.x < 0 || destination.x >= 8 || destination.y < 0 || destination.y >= 8) {
        return false;
    }

    switch (type_) {
        case PAWN: {
            if (isWhite_) {
                // White pawns can only move forward and can advance two squares in their starting position
                if (dy == 1 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return true;
                }
                if (position_.y == 1 && dy == 2 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return board.getPiece(position_.x, position_.y + 1) == 0; // Ensure that the path is unobstructed
                }
                // Diagonal advance to capture enemy piece
                if (dy == 1 && abs(dx) == 1 && board.getPiece(destination.x, destination.y) != 0) {
                    return true;
                }
            } else {
                // for black pawn
                if (dy == -1 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return true;
                }
                if (position_.y == 6 && dy == -2 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return board.getPiece(position_.x, position_.y - 1) == 0;
                }
                if (dy == -1 && abs(dx) == 1 && board.getPiece(destination.x, destination.y) != 0) {
                    return true;
                }
            }
            break;
        }

        case ROOK: {
            if (dx == 0 || dy == 0) {
                int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                for (int i = 1; i < std::max(abs(dx), abs(dy)); ++i) {
                    if (board.getPiece(position_.x + i * stepX, position_.y + i * stepY) != 0) {
                        return false;
                    }
                }
                return true;
            }
            break;
        }

        case BISHOP: {
            if (abs(dx) == abs(dy)) {
                int stepX = (dx > 0 ? 1 : -1);
                int stepY = (dy > 0 ? 1 : -1);
                for (int i = 1; i < abs(dx); ++i) {
                    if (board.getPiece(position_.x + i * stepX, position_.y + i * stepY) != 0) {
                        return false;
                    }
                }
                return true;
            }
            break;
        }

        case KNIGHT: {
            if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
                return true;
            }
            break;
        }

        case QUEEN: {
            if (dx == 0 || dy == 0) { // Horizontal or vertical movements
                int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                for (int i = 1; i < std::max(abs(dx), abs(dy)); ++i) {
                    if (board.getPiece(position_.x + i * stepX, position_.y + i * stepY) != 0) {
                        return false;
                    }
                }
                return true;
            }
            if (abs(dx) == abs(dy)) { // slope
                int stepX = (dx > 0 ? 1 : -1);
                int stepY = (dy > 0 ? 1 : -1);
                for (int i = 1; i < abs(dx); ++i) {
                    if (board.getPiece(position_.x + i * stepX, position_.y + i * stepY) != 0) {
                        return false;
                    }
                }
                return true;
            }
            break;
        }

        case KING: {
            if (abs(dx) <= 1 && abs(dy) <= 1) {
                return true;
            }
            break;
        }
    }

    return false;
}
