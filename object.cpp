#include "object.h"
#include <GL/glew.h>
//#include <glm/gtx/transform.hpp>
#include <iostream>
#include <cstdio>
#include <cstring>

// 初始化棋盘
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


// ChessBoard: 绘制8x8棋盘
void ChessBoard::draw() const {
    float thickness = 0.2f; // 棋盘的厚度

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            bool isWhite = (x + y) % 2 == 0;
            glm::vec3 color = isWhite ? glm::vec3(0.9f, 0.9f, 0.9f) : glm::vec3(0.2f, 0.2f, 0.2f);
            glColor3f(color.r, color.g, color.b);

            glPushMatrix();
            glTranslatef(x, -thickness / 2, y); // 下沉一半厚度

            // 绘制顶部面
            glBegin(GL_QUADS);
            glVertex3f(0, thickness / 2, 0);
            glVertex3f(1, thickness / 2, 0);
            glVertex3f(1, thickness / 2, 1);
            glVertex3f(0, thickness / 2, 1);
            glEnd();

            // 绘制四个侧面
            glBegin(GL_QUADS);
            // 前面
            glVertex3f(0, -thickness / 2, 1);
            glVertex3f(1, -thickness / 2, 1);
            glVertex3f(1, thickness / 2, 1);
            glVertex3f(0, thickness / 2, 1);

            // 后面
            glVertex3f(0, -thickness / 2, 0);
            glVertex3f(1, -thickness / 2, 0);
            glVertex3f(1, thickness / 2, 0);
            glVertex3f(0, thickness / 2, 0);

            // 左面
            glVertex3f(0, -thickness / 2, 0);
            glVertex3f(0, -thickness / 2, 1);
            glVertex3f(0, thickness / 2, 1);
            glVertex3f(0, thickness / 2, 0);

            // 右面
            glVertex3f(1, -thickness / 2, 0);
            glVertex3f(1, -thickness / 2, 1);
            glVertex3f(1, thickness / 2, 1);
            glVertex3f(1, thickness / 2, 0);
            glEnd();

            // 绘制底部面
            glBegin(GL_QUADS);
            glVertex3f(0, -thickness / 2, 0);
            glVertex3f(1, -thickness / 2, 0);
            glVertex3f(1, -thickness / 2, 1);
            glVertex3f(0, -thickness / 2, 1);
            glEnd();

            glPopMatrix();
        }
    }
}

bool Object::loadOBJ(const char* path, std::vector<glm::vec3>& out_vertices,
                     std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals) {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    FILE* file = fopen(path, "r");
    if (file == NULL) {
        std::cerr << "Impossible to open the file!" << std::endl;
        return false;
    }

    while (true) {
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF) break;

        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            temp_uvs.push_back(uv);
        } else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        } else if (strcmp(lineHeader, "f") == 0) {
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
            if (matches != 9) {
                std::cerr << "File can't be read by our simple parser." << std::endl;
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            uvIndices.push_back(uvIndex[0]);
            normalIndices.push_back(normalIndex[0]);

            vertexIndices.push_back(vertexIndex[1]);
            uvIndices.push_back(uvIndex[1]);
            normalIndices.push_back(normalIndex[1]);

            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[2]);
        }
    }

    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        out_vertices.push_back(temp_vertices[vertexIndices[i] - 1]);
        out_uvs.push_back(temp_uvs[uvIndices[i] - 1]);
        out_normals.push_back(temp_normals[normalIndices[i] - 1]);
    }
    return true;
}

ChessPiece::ChessPiece(PieceType type, bool isWhite, glm::vec3 position)
    : type_(type), isWhite_(isWhite), position_(position) {
    std::string filepath;
    switch (type_) {
        case PAWN: filepath = "models/pawn.obj"; break;
        case ROOK: filepath = "models/rook.obj"; break;
        case BISHOP: filepath = "models/bishop.obj"; break;
        case KNIGHT: filepath = "models/knight.obj"; break;
        case QUEEN: filepath = "models/queen.obj"; break;
        case KING: filepath = "models/king.obj"; break;
    }

    if (!Object::loadOBJ(filepath.c_str(), vertices_, uvs_, normals_)) {
        std::cerr << "Failed to load " << filepath << std::endl;
    }
}

void ChessPiece::draw() const {
    glPushMatrix();
    glTranslatef(position_.x, position_.y, position_.z); // 平移到棋盘上的对应位置

    glScalef(0.5f, 0.5f, 0.5f);

    // 调整模型方向
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f); // 绕 Y 轴旋转
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // 绕 X 轴旋转

    // 设置棋子颜色
     if (isWhite_) {
         glColor3f(1.0f, 1.0f, 1.0f); // 白棋
     } else {
         glColor3f(0.0f, 0.0f, 0.0f); // 黑棋
     }


    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < vertices_.size(); i++) {
        glVertex3f(vertices_[i].x, vertices_[i].y, vertices_[i].z);
    }
    glEnd();

    glPopMatrix();
}



//void ChessPiece::setPosition(glm::vec2 position) {
//    position_ = position;
//}

//glm::vec2 ChessPiece::getPosition() const {
//    return position_;
//}



// 棋子的合法移动规则
bool ChessPiece::isValidMove(const ChessBoard& board, glm::vec2 destination) const {
    int dx = destination.x - position_.x;
    int dy = destination.y - position_.y;

    // 确保目标位置在棋盘范围内
    if (destination.x < 0 || destination.x >= 8 || destination.y < 0 || destination.y >= 8) {
        return false;
    }

    switch (type_) {
        case PAWN: { // 兵的规则
            if (isWhite_) {
                // 白兵只能向前，起始位置可以前进两格
                if (dy == 1 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return true;
                }
                if (position_.y == 1 && dy == 2 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return board.getPiece(position_.x, position_.y + 1) == 0; // 确保路径无阻挡
                }
                // 斜向前进捕获敌方棋子
                if (dy == 1 && abs(dx) == 1 && board.getPiece(destination.x, destination.y) != 0) {
                    return true;
                }
            } else {
                // 黑兵规则类似
                if (dy == -1 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return true;
                }
                if (position_.y == 6 && dy == -2 && dx == 0 && board.getPiece(destination.x, destination.y) == 0) {
                    return board.getPiece(position_.x, position_.y - 1) == 0; // 确保路径无阻挡
                }
                if (dy == -1 && abs(dx) == 1 && board.getPiece(destination.x, destination.y) != 0) {
                    return true;
                }
            }
            break;
        }

        case ROOK: { // 车的规则
            if (dx == 0 || dy == 0) {
                // 检查路径无阻挡
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

        case BISHOP: { // 主教的规则
            if (abs(dx) == abs(dy)) { // 主教只能斜向移动
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

        case KNIGHT: { // 骑士的规则
            // 骑士可以跳过其他棋子，移动 "L" 形
            if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2)) {
                return true;
            }
            break;
        }

        case QUEEN: { // 后的规则
            // 后的移动是车和主教规则的结合
            if (dx == 0 || dy == 0) { // 水平或垂直移动
                int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                for (int i = 1; i < std::max(abs(dx), abs(dy)); ++i) {
                    if (board.getPiece(position_.x + i * stepX, position_.y + i * stepY) != 0) {
                        return false;
                    }
                }
                return true;
            }
            if (abs(dx) == abs(dy)) { // 斜向移动
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

        case KING: { // 王的规则
            // 王只能移动一格（包括对角线）
            if (abs(dx) <= 1 && abs(dy) <= 1) {
                return true;
            }
            break;
        }
    }

    return false; // 如果不符合任何规则，则非法
}
