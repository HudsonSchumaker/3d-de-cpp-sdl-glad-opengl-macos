/**
* @file Matrix3.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Matrix3 final {
public:
    float m[3][3];  // 3x3 matrix stored in column-major order

    Matrix3();
    static Matrix3 identity();
    void toArray(float* out) const;

};
