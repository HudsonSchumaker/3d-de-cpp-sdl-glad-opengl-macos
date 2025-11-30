/**
* @file V8.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "V8.h"
#include "Time.h"
#include "Window.h"
#include "SceneManager.h"
#include "../ecs/EcsManager.h"

void V8::sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
		exit(EXIT_FAILURE);
	}

    SDL_JoystickOpen(0);
    SDL_JoystickOpen(1);
    SDL_JoystickOpen(2);
    SDL_JoystickOpen(3);
}

void V8::core() {
    Time::getInstance();
}

void V8::initialize() {
    sdl();
    core();
}

void V8::shutdown() {
    Mix_HaltChannel(-1);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    delete Time::getInstance();
    delete Window::getInstance();
    delete EcsManager::getInstance();
    delete SceneManager::getInstance();
}
