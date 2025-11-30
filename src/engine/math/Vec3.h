/**
* @file Vec3.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Vec3 final {
public:
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float asArray[3];
    };

    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    static float dot(const Vec3& a, const Vec3& b);
    static Vec3  cross(const Vec3& a, const Vec3& b);
    float dot(const Vec3& b) const;
    Vec3 cross(const Vec3& b) const;

    float magnitude() const;
    float sqrMagnitude() const;
    Vec3  normalized() const;

    Vec3 operator + (const Vec3& b) const;  // a + b
    Vec3 operator - (const Vec3& b) const;  // a - b
    Vec3 operator * (const float s) const;  // a * s
    Vec3 operator / (const float s) const;  // a / s
};
