/**
* @file Matrix4.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Matrix4.h"

Matrix4::Matrix4() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m[i][j] = 0.0f;
        }
    }
}

Matrix4 Matrix4::identity() {
    // | 1  0  0  0 |
    // | 0  1  0  0 |
    // | 0  0  1  0 |
    // | 0  0  0  1 |
    Matrix4 result;
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;
    return result;
}

Matrix4 Matrix4::scale(const float sx, const float sy, const float sz) {
    // | sx 0  0  0 |
    // | 0  sy 0  0 |
    // | 0  0  sz 0 |
    // | 0  0  0  1 |
    Matrix4 result = Matrix4::identity();
    result.m[0][0] = sx;
    result.m[1][1] = sy;
    result.m[2][2] = sz;
    return result;
}

Matrix4 Matrix4::translation(const float tx, const float ty, const float tz) {
    // | 1  0  0 tx |
    // | 0  1  0 ty |
    // | 0  0  1 tz |
    // | 0  0  0  1 |
    Matrix4 result = Matrix4::identity();
    result.m[3][0] = tx;
    result.m[3][1] = ty;
    result.m[3][2] = tz;
    return result;
}

Matrix4 Matrix4::rotationX(const float rx) {
    float sin = sinf(rx);
    float cos = cosf(rx);

    // | 1    0        0     0 |
    // | 0  cos(a)  -sin(a)  0 |
    // | 0  sin(a)   cos(a)  0 |
    // | 0    0        0     1 |
    Matrix4 result = Matrix4::identity();
    result.m[1][1] = cos;
    result.m[1][2] = -sin;
    result.m[2][1] = sin;
    result.m[2][2] = cos;
    return result;
}

Matrix4 Matrix4::rotationY(const float ry) {
    float sin = sinf(ry);
    float cos = cosf(ry);

    // |  cos(a)  0  sin(a)  0 |
    // |    0     1    0     0 |
    // | -sin(a)  0  cos(a)  0 |
    // |    0     0    0     1 |
    Matrix4 result = Matrix4::identity();
    result.m[0][0] = cos;
    result.m[0][2] = sin;
    result.m[2][0] = -sin;
    result.m[2][2] = cos;
    return result;
}

Matrix4 Matrix4::rotationZ(const float rz) {
    float sin = sinf(rz);
    float cos = cosf(rz);

    // | cos(a) -sin(a)  0  0 |
    // | sin(a)  cos(a)  0  0 |
    // |   0       0     1  0 |
    // |   0       0     0  1 |
    Matrix4 result = Matrix4::identity();
    result.m[0][0] = cos;
    result.m[0][1] = -sin;
    result.m[1][0] = sin;
    result.m[1][1] = cos;
    return result;
}

Matrix4 Matrix4::rotation(const Vec3& eulerAngles) {
    Matrix4 rx = rotationX(eulerAngles.x);
    Matrix4 ry = rotationY(eulerAngles.y);
    Matrix4 rz = rotationZ(eulerAngles.z);
    return rz * ry * rx; // Note the order of multiplication
}

Matrix4 Matrix4::perspective(const float fovRad, const float aspectRatio, const float nearPlane, const float farPlane) {
    float f = 1.0f / tanf(fovRad * 0.5f);
    float nf = 1.0f / (nearPlane - farPlane);

    Matrix4 result;
    result.m[0][0] = f / aspectRatio;
    result.m[1][1] = f;
    result.m[2][2] = (farPlane + nearPlane) * nf;
    result.m[2][3] = -1.0f;
    result.m[3][2] = (2.0f * farPlane * nearPlane) * nf;
    return result;
}

Matrix4 Matrix4::lookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    Vec3 F = (target - eye).normalized();
    Vec3 S = up.cross(F).normalized();
    Vec3 U = F.cross(S);

    // |  S.x   S.y   S.z   -dot(S, eye) |
    // |  U.x   U.y   U.z   -dot(U, eye) |
    // | -F.x  -F.y  -F.z    dot(F, eye) |
    // |   0     0     0        1        |
    Matrix4 result = Matrix4::identity();
    result.m[0][0] = S.x;
    result.m[1][0] = S.y;
    result.m[2][0] = S.z;
    result.m[0][1] = U.x;
    result.m[1][1] = U.y;
    result.m[2][1] = U.z;
    result.m[0][2] = -F.x;
    result.m[1][2] = -F.y;
    result.m[2][2] = -F.z;
    result.m[3][0] = -Vec3::dot(S, eye);;
    result.m[3][1] = -Vec3::dot(U, eye);;
    result.m[3][2] = Vec3::dot(F, eye);

    return result;
}

Vec4 Matrix4::mulVec4(const Matrix4& m, const Vec4& v) {
    Vec4 result;
    result.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w;
    result.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w;
    result.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w;
    result.w = m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w;
    return result;
}

Matrix4 Matrix4::mulMat4(const Matrix4& a, const Matrix4& b) {
    Matrix4 result;
    for (int i = 0; i < 4; i++) {
        result.m[i][0] = a.m[i][0] * b.m[0][0] + a.m[i][1] * b.m[1][0] + a.m[i][2] * b.m[2][0] + a.m[i][3] * b.m[3][0];
        result.m[i][1] = a.m[i][0] * b.m[0][1] + a.m[i][1] * b.m[1][1] + a.m[i][2] * b.m[2][1] + a.m[i][3] * b.m[3][1];
        result.m[i][2] = a.m[i][0] * b.m[0][2] + a.m[i][1] * b.m[1][2] + a.m[i][2] * b.m[2][2] + a.m[i][3] * b.m[3][2];
        result.m[i][3] = a.m[i][0] * b.m[0][3] + a.m[i][1] * b.m[1][3] + a.m[i][2] * b.m[2][3] + a.m[i][3] * b.m[3][3];
    }
    return result;
}

void Matrix4::toArray(float* out) const {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out[j * 4 + i] = m[i][j]; // column-major order
        }
    }
}

Vec4 Matrix4::operator*(const Vec4& v) const {
    return mulVec4(*this, v);
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
    return mulMat4(*this, other);
}
