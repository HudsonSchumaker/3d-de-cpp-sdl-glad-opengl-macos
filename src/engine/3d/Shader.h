/**
* @file Shader.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "ShaderSource.h"

enum class ShaderType {
    VERTEX,
    FRAGMENT,
	GEOMETRY,
	TESS_CONTROL,
	TESS_EVALUATION,
	COMPUTE
};

class Shader final {
private:
    GLuint id;
    ShaderType type;
    const GLchar* src;

public:
    Shader(const std::string& source, ShaderType type);
    ~Shader();

    bool compile();
    GLuint getId() const;
    ShaderType getType() const;
};
