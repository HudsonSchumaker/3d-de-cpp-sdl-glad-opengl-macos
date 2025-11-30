/**
* @file SplashScreen.cpp
* @author Hudson Schumaker
* @brief Defines the SplashScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2025, Dodoi-Lab
*/
#include "SplashScreen.h"

SplashScreen::SplashScreen() {
    // nextScene = "MainMenu";
    background = { 1.0f, 1.0f, 1.0f, 1.0f }; // White background
}

SplashScreen::~SplashScreen() {
    unload();
}

void SplashScreen::load() {
    // Load resources for the splash screen here
    isRunning = true;
}

short SplashScreen::run() {
    isRunning = true;
    load();
    while (isRunning) {
        input();
        update();
        render();
    }

    return exit;
}

void SplashScreen::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
            exit = 1; 
        }
    }
}

void SplashScreen::update() { 
    Time::getInstance()->updateDeltaTime();
    
}

void SplashScreen::render() {
    beginRender();

    // Render splash screen content here
    // For example, draw a logo or text

    endRender();
}