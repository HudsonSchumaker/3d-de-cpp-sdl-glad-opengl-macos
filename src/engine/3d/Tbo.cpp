/**
* @file Tbo.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Tbo.h"

Tbo::Tbo() {
    glGenTextures(1, &id);
}

Tbo::~Tbo() {
    glDeleteTextures(1, &id);
}

void Tbo::bind() const {
    glBindTexture(GL_TEXTURE_BUFFER, id);
}

void Tbo::unbind() const {
    glBindTexture(GL_TEXTURE_BUFFER, 0);
}
