/**
* @file Entity.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Entity.h"

Uint32 Entity::nextId = 0;
Entity::Entity() : id(++nextId) {}

Uint32 Entity::getId() const { return id; }
