/**
* @file Vao.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Vao.h"

Vao::Vao() {
    glGenVertexArrays(1, &id);
}

Vao::~Vao() {
    glDeleteVertexArrays(1, &id);
}

void Vao::bind() const {
    glBindVertexArray(id);
}

void Vao::unbind() const {
    glBindVertexArray(0);
}

GLuint Vao::getId() const {
    return id;
}
