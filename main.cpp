#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <ctime>
#include "renderer.h"
#include "shader.h"
#include "camera.h"
#include "navigationcontrols.h"

// Global variables
Camera* camera = nullptr;
NavigationControls* controls = nullptr;
Renderer renderer;
ChessBoard chessBoard;
std::vector<ChessPiece> chessPieces;
bool isWhiteTurn = true;

void setupOpenGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.3f, 0.1f); // background blue foncé

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0, 1.0, 1.0, 100.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     // Camera fix
     gluLookAt(4.0, 8.0, 17.0,
               4.0, 0.0, 0.0,
               0.0, 1.0, 0.0);

}


void initializeGame() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            chessBoard.setPiece(x, y, 0);
        }
    }

    // pawn white
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, true, glm::vec3(i + 0.5f, -0.5f, 1 + 0.5f)); // 白棋兵
        chessBoard.setPiece(i, 1, ChessPiece::PAWN);
    }

    // pawn black
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, false, glm::vec3(i + 0.5f, -0.5f, 6 + 0.5f)); // 黑棋兵
        chessBoard.setPiece(i, 6, ChessPiece::PAWN);
    }

    // others white
    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec3(0 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋车
    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec3(1 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋马
    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec3(2 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋象
    chessPieces.emplace_back(ChessPiece::QUEEN, true, glm::vec3(3 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋后
    chessPieces.emplace_back(ChessPiece::KING, true, glm::vec3(4 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋王
    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec3(5 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋象
    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec3(6 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋马
    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec3(7 + 0.5f, -0.5f, 0 + 0.5f)); // 白棋车

    // others black
    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec3(0 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋车
    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec3(1 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋马
    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec3(2 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋象
    chessPieces.emplace_back(ChessPiece::QUEEN, false, glm::vec3(3 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋后
    chessPieces.emplace_back(ChessPiece::KING, false, glm::vec3(4 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋王
    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec3(5 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋象
    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec3(6 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋马
    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec3(7 + 0.5f, -0.5f, 7 + 0.5f)); // 黑棋车
}


void initializeCamera(GLFWwindow* window, float width, float height) {
    camera = new Camera(width, height);
    controls = new NavigationControls(window, camera);
}


void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderer.render(chessBoard, chessPieces, camera->getViewMatrix(), camera->getProjectionMatrix());
    glfwSwapBuffers(glfwGetCurrentContext());
}


int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 800, "Chess Game", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    setupOpenGL();
    initializeGame();
    initializeCamera(window, 800, 800);
    // srand(static_cast<unsigned int>(time(0))); // 初始化随机数种子


    while (!glfwWindowShouldClose(window)) {
//        gameLoop(window); // 处理用户输入和游戏逻辑
        float deltaTime = 0.016f;
        controls->update(deltaTime, nullptr);
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clean
    delete camera;
    delete controls;
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

