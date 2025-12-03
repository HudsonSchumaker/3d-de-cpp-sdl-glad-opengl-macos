/**
* @file Program.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "Shader.h"
#include "../math/Vec2.h"
#include "../math/Vec3.h"
#include "../math/Vec4.h"
#include "../math/Matrix3.h"
#include "../math/Matrix4.h"

class Program final {
private:
    GLuint id;

public:
    Program();
    ~Program();

    bool link(const Shader& vertexShader, const Shader& fragmentShader);
    void use() const;
    void unbind() const;

    GLint getUniformLocation(const std::string& name) const;
    void setUniform(const std::string& name, GLint value) const;
    void setUniform(const std::string& name, GLfloat value) const;
    void setUniform(const std::string& name, Vec2& vector) const;
    void setUniform(const std::string& name, Vec3& vector) const;
    void setUniform(const std::string& name, Vec4& vector) const;
    void setUniform(const std::string& name, const Matrix3& matrix) const;
    void setUniform(const std::string& name, const Matrix4& matrix) const;

    GLuint getId() const;
};
