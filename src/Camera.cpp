//
// Created by micha on 1/20/2022.
//

#include "Camera.h"

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

