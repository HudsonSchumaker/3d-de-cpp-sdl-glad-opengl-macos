/**
* @file Program.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Program.h"

Program::Program() {
    id = glCreateProgram();
}

Program::~Program() {
    glDeleteProgram(id);
}

bool Program::link(const Shader& vertexShader, const Shader& fragmentShader) {
    glAttachShader(id, vertexShader.getId());
    glAttachShader(id, fragmentShader.getId());
    glLinkProgram(id);

    GLint success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        GLint length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
        std::vector<GLchar> infoLog(length);
        glGetProgramInfoLog(id, length, nullptr, infoLog.data());
        std::cerr << "Program linking failed:" << infoLog.data() << std::endl;
        return false;
    }
    return true;
}

void Program::use() const {
    glUseProgram(id);
}

void Program::unbind() const {
    glUseProgram(0);
}

GLint Program::getUniformLocation(const std::string& name) const {
    return glGetUniformLocation(id, name.c_str());
}

void Program::setUniform(const std::string& name, GLint value) const {
    glUniform1i(getUniformLocation(name), value);
}

void Program::setUniform(const std::string& name, GLfloat value) const {
    glUniform1f(getUniformLocation(name), value);
}

void Program::setUniform(const std::string& name, Vec2& vector) const {
    glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Program::setUniform(const std::string& name, Vec3& vector) const {
    glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Program::setUniform(const std::string& name, Vec4& vector) const {
    glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void Program::setUniform(const std::string& name, const Matrix3& matrix) const {
    float array[9];
    matrix.toArray(array);
    glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, array);
}

void Program::setUniform(const std::string& name, const Matrix4& matrix) const {
    float array[16];
    matrix.toArray(array);
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, array);
}

GLuint Program::getId() const {
    return id;
}
