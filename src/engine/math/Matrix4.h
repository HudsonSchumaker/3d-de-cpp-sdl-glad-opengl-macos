/**
* @file Matrix4.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "../math/Vec3.h"
#include "../math/Vec4.h"

class Matrix4 final {
public:
    float m[4][4];  // 4x4 matrix stored in column-major order

    Matrix4();
    static Matrix4 identity();
    
    static Matrix4 scale(const float x, const float y, const float z);
    static Matrix4 translation(const float x, const float y, const float z);

    static Matrix4 rotation(const Vec3& eulerAngles);
    static Matrix4 rotationX(const float angleRad);
    static Matrix4 rotationY(const float angleRad);
    static Matrix4 rotationZ(const float angleRad);

    static Matrix4 perspective(const float fovRad, const float aspectRatio, const float nearPlane, const float farPlane);
    static Matrix4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up);

    static Vec4 mulVec4(const Matrix4& matrix, const Vec4& vector);
    static Matrix4 mulMat4(const Matrix4& a, const Matrix4& b);

    void toArray(float* out) const;

    Vec4 operator*(const Vec4& vec) const;
    Matrix4 operator*(const Matrix4& other) const;
};
