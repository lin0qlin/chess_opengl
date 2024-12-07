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
//    glEnable(GL_DEPTH_TEST); // for 3D
    glDisable(GL_DEPTH_TEST); //for 2D

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 8.0, 0.0, 8.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

}


void initializeGame() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            chessBoard.setPiece(x, y, 0);
        }
    }

    // pawn white
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, true, glm::vec2(i, 1));
        chessBoard.setPiece(i, 1, ChessPiece::PAWN);
    }

    // pawn black
    for (int i = 0; i < 8; ++i) {
        chessPieces.emplace_back(ChessPiece::PAWN, false, glm::vec2(i, 6));
        chessBoard.setPiece(i, 6, ChessPiece::PAWN);
    }

    // others white
    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec2(0, 0));
    chessBoard.setPiece(0, 0, ChessPiece::ROOK);

    chessPieces.emplace_back(ChessPiece::ROOK, true, glm::vec2(7, 0));
    chessBoard.setPiece(7, 0, ChessPiece::ROOK);

    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec2(1, 0));
    chessBoard.setPiece(1, 0, ChessPiece::KNIGHT);

    chessPieces.emplace_back(ChessPiece::KNIGHT, true, glm::vec2(6, 0));
    chessBoard.setPiece(6, 0, ChessPiece::KNIGHT);

    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec2(2, 0));
    chessBoard.setPiece(2, 0, ChessPiece::BISHOP);

    chessPieces.emplace_back(ChessPiece::BISHOP, true, glm::vec2(5, 0));
    chessBoard.setPiece(5, 0, ChessPiece::BISHOP);

    chessPieces.emplace_back(ChessPiece::QUEEN, true, glm::vec2(3, 0));
    chessBoard.setPiece(3, 0, ChessPiece::QUEEN);

    chessPieces.emplace_back(ChessPiece::KING, true, glm::vec2(4, 0));
    chessBoard.setPiece(4, 0, ChessPiece::KING);

    // others black
    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec2(0, 7));
    chessBoard.setPiece(0, 7, ChessPiece::ROOK);

    chessPieces.emplace_back(ChessPiece::ROOK, false, glm::vec2(7, 7));
    chessBoard.setPiece(7, 7, ChessPiece::ROOK);

    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec2(1, 7));
    chessBoard.setPiece(1, 7, ChessPiece::KNIGHT);

    chessPieces.emplace_back(ChessPiece::KNIGHT, false, glm::vec2(6, 7));
    chessBoard.setPiece(6, 7, ChessPiece::KNIGHT);

    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec2(2, 7));
    chessBoard.setPiece(2, 7, ChessPiece::BISHOP);

    chessPieces.emplace_back(ChessPiece::BISHOP, false, glm::vec2(5, 7));
    chessBoard.setPiece(5, 7, ChessPiece::BISHOP);

    chessPieces.emplace_back(ChessPiece::QUEEN, false, glm::vec2(3, 7));
    chessBoard.setPiece(3, 7, ChessPiece::QUEEN);

    chessPieces.emplace_back(ChessPiece::KING, false, glm::vec2(4, 7));
    chessBoard.setPiece(4, 7, ChessPiece::KING);
}


glm::vec2 getPlayerInput(GLFWwindow* window) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    int x = static_cast<int>(xpos / (800 / 8));
    int y = static_cast<int>((800 - ypos) / (800 / 8));
    return glm::vec2(x, y);
}

ChessPiece* getSelectedPiece(glm::vec2 position) {
    for (auto& piece : chessPieces) {
        if (piece.getPosition() == position && piece.isWhite() == isWhiteTurn) {
            return &piece;
        }
    }
    return nullptr;
}

void movePiece(ChessPiece& piece, glm::vec2 destination) {
    if (piece.isValidMove(chessBoard, destination)) {
        if (chessBoard.getPiece(destination.x, destination.y) != 0) {
            chessBoard.removePiece(destination.x, destination.y);
        }

        chessBoard.setPiece(destination.x, destination.y, piece.getType());
        chessBoard.removePiece(piece.getPosition().x, piece.getPosition().y);
        piece.setPosition(destination);

        isWhiteTurn = !isWhiteTurn;
    }
}

void gameLoop(GLFWwindow* window) {
    static glm::vec2 selectedPosition(-1, -1);

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        glm::vec2 clickPosition = getPlayerInput(window);

        if (selectedPosition == glm::vec2(-1, -1)) {
            // first turn
            ChessPiece* selectedPiece = getSelectedPiece(clickPosition);
            if (selectedPiece) {
                selectedPosition = clickPosition;
            }
        } else {
            // second turn
            ChessPiece* selectedPiece = getSelectedPiece(selectedPosition);
            if (selectedPiece) {
                movePiece(*selectedPiece, clickPosition);
            }
            selectedPosition = glm::vec2(-1, -1); // reset
        }
    }
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.render(chessBoard, chessPieces);
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
    srand(static_cast<unsigned int>(time(0)));


    while (!glfwWindowShouldClose(window)) {
        gameLoop(window);
        render();
        glfwPollEvents();
    }

    // clean
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
