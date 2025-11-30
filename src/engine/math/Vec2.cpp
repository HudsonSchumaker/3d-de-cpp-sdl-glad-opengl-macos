/**
* @file Vec2.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Vec2.h"

float Vec2::dot(const Vec2 &other) const {
    return x * other.x + y * other.y;
}

float Vec2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

float Vec2::magnitudeSquared() const {
    return x * x + y * y;
}

Vec2 Vec2::normalized() const {
    float mag = magnitude();
    return (mag > 0.0f) ? Vec2(x / mag, y / mag) : Vec2();
}

Vec2& Vec2::normalize() {
    float mag = magnitude();
    if (mag > 0.0f){
        x /= mag;
        y /= mag;
    }
    return *this;
}

Vec2 Vec2::operator+(const Vec2 &other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2 &other) const {
    return Vec2(x - other.x, y - other.y);
}
