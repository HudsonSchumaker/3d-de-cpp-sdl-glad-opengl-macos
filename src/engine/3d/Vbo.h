/**
* @file Vbo.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Vbo final {
private:
    GLuint id;

public:
    Vbo();
    ~Vbo();

    void bind() const;
    void unbind() const;
    GLuint getId() const;
};
