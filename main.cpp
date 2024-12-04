#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "renderer.h"
#include "shader.h"
#include <vector>
#include <ctime>

ChessBoard chessBoard;
std::vector<ChessPiece> chessPieces;
bool isWhiteTurn = true;
Renderer renderer;

void setupOpenGL() {
    glEnable(GL_DEPTH_TEST); // 启用深度测试
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);


    // 设置投影矩阵为正交投影
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluOrtho2D(0.0, 8.0, 0.0, 8.0); // 设置为适合棋盘的范围（0-8）
    gluPerspective(45.0, 1.0, 1.0, 100.0); // 透视投影 (45°视角, 宽高比为1, 近平面1, 远平面100)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0, 10.0, 20.0,  // 相机位置 (x, y, z)
              4.0, 0.0, 0.0,   // 相机观察点 (中心位置)
              0.0, 1.0, 0.0);  // 相机的向上向量
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f); // 深灰色背景
}


void initializeGame() {
    // 清空棋盘状态
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            chessBoard.setPiece(x, y, 0);
        }
    }

    // 初始化白棋兵
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, true, glm::vec3(i + 0.5f, -0.5f, 1 + 0.5f)); // 白棋兵
        chessBoard.setPiece(i, 1, ChessPiece::PAWN);
    }

    // 初始化黑棋兵
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, false, glm::vec3(i + 0.5f, -0.5f, 6 + 0.5f)); // 黑棋兵
        chessBoard.setPiece(i, 6, ChessPiece::PAWN);
    }

    // 初始化白棋主要棋子
    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec3(0 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋车
    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec3(1 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋马
    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec3(2 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋象
    chessPieces.emplace_back(ChessPiece::QUEEN, true, glm::vec3(3 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋后
    chessPieces.emplace_back(ChessPiece::KING, true, glm::vec3(4 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋王
    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec3(5 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋象
    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec3(6 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋马
    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec3(7 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋车

    // 初始化黑棋主要棋子
    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec3(0 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋车
    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec3(1 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋马
    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec3(2 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋象
    chessPieces.emplace_back(ChessPiece::QUEEN, false, glm::vec3(3 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋后
    chessPieces.emplace_back(ChessPiece::KING, false, glm::vec3(4 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋王
    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec3(5 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋象
    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec3(6 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋马
    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec3(7 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋车
}



/*
glm::vec2 getPlayerInput(GLFWwindow* window) {
    // 简单的输入模拟：点击某个格子将棋子移动到此处
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    int x = static_cast<int>(xpos / (800 / 8)); // 将屏幕坐标转换为棋盘坐标
    int y = static_cast<int>((800 - ypos) / (800 / 8));
    return glm::vec2(x, y);
}

ChessPiece* getSelectedPiece(glm::vec2 position) {
    // 查找当前位置的棋子
    for (auto& piece : chessPieces) {
        if (piece.getPosition() == position && piece.isWhite() == isWhiteTurn) {
            return &piece;
        }
    }
    return nullptr; // 未找到合法棋子
}

void movePiece(ChessPiece& piece, glm::vec2 destination) {
    if (piece.isValidMove(chessBoard, destination)) {
        // 捕获目标位置的棋子
        if (chessBoard.getPiece(destination.x, destination.y) != 0) {
            chessBoard.removePiece(destination.x, destination.y);
        }

        // 更新棋盘和棋子状态
        chessBoard.setPiece(destination.x, destination.y, piece.getType());
        chessBoard.removePiece(piece.getPosition().x, piece.getPosition().y);
        piece.setPosition(destination);

        isWhiteTurn = !isWhiteTurn; // 切换到另一方
    }
}

void gameLoop(GLFWwindow* window) {
    static glm::vec2 selectedPosition(-1, -1); // 选中的格子

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        glm::vec2 clickPosition = getPlayerInput(window);

        if (selectedPosition == glm::vec2(-1, -1)) {
            // 第一次点击，选择棋子
            ChessPiece* selectedPiece = getSelectedPiece(clickPosition);
            if (selectedPiece) {
                selectedPosition = clickPosition;
            }
        } else {
            // 第二次点击，尝试移动棋子
            ChessPiece* selectedPiece = getSelectedPiece(selectedPosition);
            if (selectedPiece) {
                movePiece(*selectedPiece, clickPosition);
            }
            selectedPosition = glm::vec2(-1, -1); // 重置选择
        }
    }
}
*/

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer.render(chessBoard, chessPieces);
    glfwSwapBuffers(glfwGetCurrentContext());
}

int main() {
    // 初始化 GLFW
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 800, "Chess Game", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    setupOpenGL();  // 设置 OpenGL 状态
    initializeGame(); // 初始化棋盘和棋子
    srand(static_cast<unsigned int>(time(0))); // 初始化随机数种子

    // 主循环
    while (!glfwWindowShouldClose(window)) {
//        gameLoop(window); // 处理用户输入和游戏逻辑
        render();         // 渲染棋盘和棋子
        glfwPollEvents(); // 处理窗口事件
    }

    // 清理
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
