/**
* @file Tbo.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Tbo final {
public:
    Tbo();
    ~Tbo();

    void bind() const;
    void unbind() const;

private:
    GLuint id;
};
