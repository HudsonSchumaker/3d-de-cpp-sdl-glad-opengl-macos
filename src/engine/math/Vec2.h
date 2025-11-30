/**
* @file Vec2.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Vec2 final {
public:
    union {
        struct {
            float x;
            float y;
        };
        float asArray[2];
    };

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x, float y) : x(x), y(y) {}

    float dot(const Vec2& other) const;
    float magnitude() const;
    float magnitudeSquared() const; 
    Vec2 normalized() const;
    Vec2& normalize();

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
};
