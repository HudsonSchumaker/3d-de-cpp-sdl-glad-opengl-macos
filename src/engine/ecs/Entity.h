/**
* @file Entity.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Entity final {
private:
    static Uint32 nextId;
    Uint32 id;

public:
    const static Uint32 MAX_ENTITIES = 5000;
    bool active = true;

    Entity();
    Uint32 getId() const;
};
