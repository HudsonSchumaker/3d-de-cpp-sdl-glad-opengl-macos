/**
* @file Vec3.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Vec3.h"

float Vec3::dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Vec3::cross(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

float Vec3::dot(const Vec3& b) const { return Vec3::dot(*this, b); }  

Vec3 Vec3::cross(const Vec3& b) const { return Vec3::cross(*this, b); }

float Vec3::magnitude() const {
    return sqrtf(x * x + y * y + z * z);
}

float Vec3::sqrMagnitude() const {
    return x * x + y * y + z * z;
}

Vec3 Vec3::normalized() const {
    float mag = magnitude();
    if (mag == 0.0f) return Vec3(0.0f, 0.0f, 0.0f);
    return Vec3(x / mag, y / mag, z / mag);
}

Vec3 Vec3::operator + (const Vec3& b) const {
    return Vec3(x + b.x, y + b.y, z + b.z);
}

Vec3 Vec3::operator - (const Vec3& b) const {
    return Vec3(x - b.x, y - b.y, z - b.z);
}

Vec3 Vec3::operator * (const float s) const {
    return Vec3(x * s, y * s, z * s);
}

Vec3 Vec3::operator / (const float s) const {
    return Vec3(x / s, y / s, z / s);
}
