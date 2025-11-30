/**
* @file Transform.h
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
#include "../ecs/Component.h"

class Transform : public Component {
public:
    Vec3 position = {0, 0, 0};
    Vec3 rotation = {0, 0, 0}; // Euler angles (pitch, yaw, roll)
    Vec3 scale = {1, 1, 1};

    Transform() : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f) {}
    Transform(const Vec3& pos, const Vec3& rot, const Vec3& scl) : position(pos), rotation(rot), scale(scl) {}

    Matrix4 getModelMatrix() const {
        Matrix4 T = Matrix4::translation(position.x, position.y, position.z);
        Matrix4 R = Matrix4::rotation(rotation);
        Matrix4 S = Matrix4::scale(scale.x, scale.y, scale.z);
        return T * R * S; // Note the order of multiplication
    }
};
