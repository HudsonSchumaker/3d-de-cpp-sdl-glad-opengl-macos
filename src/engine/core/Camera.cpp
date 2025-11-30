/**
* @file Camera.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Camera.h"
#include "../math/DeMath.h"
#include "../core/Window.h"

Camera::Camera() {
	fov = 60.0f;
	zFar = 100.0f;
	zNear = 0.1f;

	yaw = 0.0f;
	pitch = 0.0f;

	eye = Vec3(0.0f, 0.0f, 0.0f);
	target = Vec3(0.0f, 0.0f, 0.0f);
	up = worldUp;
}

void Camera::setFov(float fov) {
    this->fov = fov;
}

Matrix4 Camera::getViewMatrix() const {
    return Matrix4::lookAt(eye, target, up);
}

Matrix4 Camera::getProjectionMatrix() const {
    float aspectRatio = Window::getInstance()->getAspectRatio();
    return Matrix4::perspective(DeMath::deg2Rad(fov), aspectRatio, zNear, zFar);
}

float Camera::getFov() const {
    return fov;
}

const Vec3& Camera::getUp() const {
    return up;
}

const Vec3& Camera::getTarget() const {
    return target;
}

const Vec3& Camera::getEye() const {
    return eye;
}
