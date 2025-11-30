/**
* @file Vec4.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Vec4 final{
public:
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float asArray[4];
    };

    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

   
};