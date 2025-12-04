/**
* @file Time.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Time final {
public:
    inline static Time* instance = nullptr;
    static Time* getInstance();

    float update();
    float getDeltaTime() const;
    float getElapsedTime() const;
    float getFPS() const;
    ~Time() = default;

private:
    Time() = default;

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    float currentTime = 0.0f;
    float fps = 0.0f;
};
