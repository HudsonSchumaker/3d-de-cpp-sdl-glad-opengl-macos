/**
* @file Camera.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "../math/Vec3.h"
#include "../math/Matrix4.h"

class Camera {
protected:
	float fov;   // Field of view in degrees
	float zFar;  // Far clipping plane
	float zNear; // Near clipping plane
	
	// Euler angles in radians
	float yaw;
	float pitch;

	// Camera vectors
	Vec3 eye;    // position
	Vec3 target; 
	Vec3 up;
	
	Camera();
	virtual void update() = 0;

public:
    const Vec3 worldUp = Vec3(0.0f, 1.0f, 0.0f);

    void setFov(float fov);
    virtual void setPosition(const Vec3& position) = 0;
	virtual void setRotation(float yaw, float pitch) = 0;

	float getFov() const;
	const Vec3& getUp() const;
	const Vec3& getEye() const;
    const Vec3& getTarget() const;

	Matrix4 getViewMatrix() const;
	Matrix4 getProjectionMatrix() const;
};
