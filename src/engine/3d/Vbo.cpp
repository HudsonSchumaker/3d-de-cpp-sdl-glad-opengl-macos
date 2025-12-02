/**
* @file Vbo.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Vbo.h"

Vbo::Vbo() {
    glGenBuffers(1, &id);
}
