/**
* @file Main.cpp
* @author Hudson Schumaker
* @brief Defines main function.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Pch.h"
#include "engine/core/V8.h"
#include "engine/core/Time.h"
#include "engine/3d/Shader.h"
#include "engine/core/Window.h"

void quit();
void setUp(std::pair<bool, bool> displayFlags);
std::pair<bool, bool> args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    setUp(args(argc, argv));
  
    Time* time = Time::getInstance();


    Shader v = Shader(VERTEX_DEFAULT, ShaderType::VERTEX);
    v.compile();

    Shader f = Shader(FRAGMENT_DEFAULT, ShaderType::FRAGMENT);
    f.compile();

    bool running = true;
    while (running) {
        SDL_Event event;
	    while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    Window::getInstance()->onWindowResize(event.window.data1, event.window.data2);
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
            }
        }
        
        time->update();
        Window::getInstance()->setTitle(" - FPS: " + std::to_string(static_cast<int>(time->getFPS())));
    }
 
    quit();
    return 0;
}

void setUp(std::pair<bool, bool> displayFlags) {
    V8::initialize();

    bool isFullscreen = displayFlags.first;
    bool isVsync = displayFlags.second;

    Window::getInstance()->setGfxContext(isFullscreen, isVsync);
}

void quit() {
    V8::shutdown();
}

std::pair<bool, bool> args(int argc, char* argv[]) {
    bool isFullscreen = false;
    bool isVsync = true;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--f") {
            isFullscreen = true;
        }
        
        if (arg == "--vsync") {
            isVsync = true;
        }
    }

    return {isFullscreen, isVsync};
}
