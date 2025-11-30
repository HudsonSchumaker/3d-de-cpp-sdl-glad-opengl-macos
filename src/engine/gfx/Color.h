/**
* @file Color.h
* @author Hudson Schumaker
* @brief Defines the Color class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "../math/Vec4.h"

class Color final {
public:
    float r;
    float g;
    float b;
    float a;

    Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}
    Color(float red, float green, float blue, float alpha = 1.0f) : r(red), g(green), b(blue), a(alpha) {}   
};
