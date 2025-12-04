/**
* @file Time.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Time.h"

Time* Time::getInstance() {
    if (instance == nullptr) {
        instance = new Time();
    }
    return instance;
}

float Time::update() {
    double frameStart = SDL_GetTicks64() / 1000.0;
    const double targetFrameTime = Def::TARGET_FRAME_TIME;

    double frameTime = frameStart - lastFrame;

    if (frameTime < targetFrameTime) {
        while ((SDL_GetTicks64() / 1000.0) - lastFrame < targetFrameTime) {}
        frameStart = SDL_GetTicks64() / 1000.0;
        frameTime = frameStart - lastFrame;
    }

    deltaTime = static_cast<float>(frameTime);
    lastFrame = frameStart;

    fps = (deltaTime > 0.0f) ? (1.0f / deltaTime) : 0.0f;
    currentTime += deltaTime;
    
    return deltaTime;
}

float Time::getDeltaTime() const {
    return deltaTime;
}

float Time::getElapsedTime() const {
    return currentTime;
}

float Time::getFPS() const {
    return fps;
}
