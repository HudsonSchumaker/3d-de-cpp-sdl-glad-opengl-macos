/**
* @file Shader.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Shader.h"

Shader::Shader(const std::string& source, ShaderType type) : type(type) {
    src = source.c_str();
    GLenum shaderType;

    switch (type) {
        case ShaderType::VERTEX:
            shaderType = GL_VERTEX_SHADER;
            break;
        case ShaderType::FRAGMENT:
            shaderType = GL_FRAGMENT_SHADER;
            break;
        default:
            throw std::runtime_error("Unknown shader type");
    }
    id = glCreateShader(shaderType);
}

Shader::~Shader() {
    glDeleteShader(id);
}

bool Shader::compile() {
    bool success = true;
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    GLint compiled;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        success = false;

        GLint length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        std::vector<GLchar> infoLog(length);
        glGetShaderInfoLog(id, 512, nullptr, infoLog.data());
        std::cerr << "Shader compilation failed: " << infoLog.data() << std::endl;
    }
    return success;
}

GLuint Shader::getId() const {
    return id;
}

ShaderType Shader::getType() const {
    return type;
}
