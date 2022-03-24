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
    float speed;

    explicit Camera(const glm::vec3 &position) : position(position) {
        front = glm::vec3(0.0f, 0.0f, -1.0f);
        up = glm::vec3(0.0f, 1.0f, 0.0f);

        fov = 45.0f;
        pitch = 0.0f;
        yaw = -90.0f;

        speed = 1.0f;
    }

    glm::mat4 getViewMatrix();

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
        auto cameraSpeed = static_cast<float>(12 * deltaTime * speed);
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

    void rotateWithMouse(float xoffset, float yoffset, bool constrainPitch = true) {
        float sensitivity = 0.25f; // change this value to your liking

        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += yoffset;

        // make sure that when camera.pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch) {
            if (pitch > 89.0f)
                pitch = 89.0f;
            else if (pitch < -89.0f)
                pitch = -89.0f;
        }

        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(front);
    }
};

#endif //LEARNOPENGL_CAMERA_H
