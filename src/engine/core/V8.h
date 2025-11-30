/**
* @file V8.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class V8 final {
private:
    static void sdl();
    static void core();
    
public:
    static void initialize();
    static void shutdown();
};
