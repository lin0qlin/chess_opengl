#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    glm::mat4 getViewMatrix() const; // 获取视图矩阵
    void processKeyboard(const std::string& direction, float deltaTime); // 键盘控制
    void processMouseMovement(float xOffset, float yOffset); // 鼠标控制

    void setPosition(const glm::vec3& position);
    glm::vec3 getPosition() const;

private:
    glm::vec3 position_;
    glm::vec3 front_;
    glm::vec3 up_;
    glm::vec3 right_;
    glm::vec3 worldUp_;

    float yaw_;
    float pitch_;
    float movementSpeed_;
    float mouseSensitivity_;

    void updateCameraVectors(); // 更新相机方向向量
};

#endif // CAMERA_H

