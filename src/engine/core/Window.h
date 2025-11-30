/**
* @file Window.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class Window final {
private:
    inline static Window* instance = nullptr;
    SDL_Window* sdlWindow = nullptr;
    SDL_GLContext glContext = nullptr;

    int gfxWidth = 0;
    int gfxHeight = 0;
    bool vsyncEnabled = true;
    std::string title = "Dodoi-Engine";

    Window() = default;

    void setIcon();
    void initGlad();
    void createWindow(Uint32 windowFlags);
    void createOpenGlContext();
    void setOpenGlAttributes();

public:
    ~Window();
    static Window* getInstance();
    void onWindowResize(const int width, const int height);
    void setGfxContext(bool isFullscreen = false, bool isVsync = true);
    void setVsyncEnabled(bool isVsync);
    void setTitle(const std::string& title);

    SDL_Window* getWindow() const;
    SDL_GLContext getGlContext() const;
    float getAspectRatio() const;
    std::pair<int, int> getWindowSize() const;
    std::string getTitle() const;
};
