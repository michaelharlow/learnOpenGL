#ifndef LEARNOPENGL_CAMERA_H
#define LEARNOPENGL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    float yaw, pitch, fov;

    explicit Camera(const glm::vec3 &position) : position(position) {
        front = glm::vec3(0.0f, 0.0f, -1.0f);
        up = glm::vec3(0.0f, 1.0f, 0.0f);

        fov = 45.0f;
        pitch = 0.0f;
        yaw = -90.0f;
    }

    void zoom(float zoomAmount) {
        fov -= zoomAmount;
        if (fov < 1.0f) {
            fov = 1.0f;
        }
        if (fov > 90.0f) {
            fov = 90.0f;
        }
    }

    void move(CameraMovement direction, float deltaTime) {
        auto cameraSpeed = static_cast<float>(3 * deltaTime);
        if (direction == FORWARD) {
            position += cameraSpeed * front;
        } else if (direction == BACKWARD) {
            position -= cameraSpeed * front;
        } else if (direction == LEFT) {
            position -= glm::normalize(glm::cross(front, up)) * cameraSpeed;
        } else if (direction == RIGHT) {
            position += glm::normalize(glm::cross(front, up)) * cameraSpeed;
        }
    }
};

#endif //LEARNOPENGL_CAMERA_H
