#include "control.h"

Control::Control(Camera& camera)
    : camera_(camera), firstMouse_(true), lastX_(400), lastY_(300) {}

void Control::processInput(GLFWwindow* window, float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera_.processKeyboard("FORWARD", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera_.processKeyboard("BACKWARD", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera_.processKeyboard("LEFT", deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera_.processKeyboard("RIGHT", deltaTime);
}

void Control::processMouse(GLFWwindow* window) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (firstMouse_) {
        lastX_ = xpos;
        lastY_ = ypos;
        firstMouse_ = false;
    }

    float xOffset = xpos - lastX_;
    float yOffset = lastY_ - ypos; // 反转 y 坐标

    lastX_ = xpos;
    lastY_ = ypos;

    camera_.processMouseMovement(xOffset, yOffset);
}
