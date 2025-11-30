/**
* @file Ebo.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Ebo final {
private:
    GLuint id;

public:
    Ebo();
    ~Ebo();

    void bind() const;
    void unbind() const;
};
