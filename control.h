#ifndef CONTROL_H
#define CONTROL_H

#include "camera.h"
#include <GLFW/glfw3.h>

class Control {
public:
    Control(Camera& camera);

    void processInput(GLFWwindow* window, float deltaTime);
    void processMouse(GLFWwindow* window);

private:
    Camera& camera_;
    bool firstMouse_;
    float lastX_;
    float lastY_;
};

#endif // CONTROL_H
