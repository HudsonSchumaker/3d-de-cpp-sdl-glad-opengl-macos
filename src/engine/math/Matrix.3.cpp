/**
* @file Matrix3.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/

#include "Matrix3.h"

Matrix3::Matrix3() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m[i][j] = 0.0f;
        }
    }
}

Matrix3 Matrix3::identity() {
    // | 1  0  0 |
    // | 0  1  0 |
    // | 0  0  1 |
    Matrix3 result;
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    return result;
}

void Matrix3::toArray(float* out) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out[j * 3 + i] = m[i][j]; // column-major order
        }
    }
}
