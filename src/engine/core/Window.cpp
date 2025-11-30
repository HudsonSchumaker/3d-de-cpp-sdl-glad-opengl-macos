/**
* @file Window.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Window.h"

Window::~Window() {
    if (glContext) {
        SDL_GL_DeleteContext(glContext);
    }
    if (sdlWindow) {
        SDL_DestroyWindow(sdlWindow);
    }
}

Window* Window::getInstance() {
    if (instance == nullptr) {
        instance = new Window();
    }
    return instance;
}

void Window::onWindowResize(const int width, const int height) {
    gfxWidth = width;
    gfxHeight = height;

    SDL_SetWindowSize(sdlWindow, width, height);
    glViewport(0, 0, width, height);
}

void Window::setGfxContext(bool isFullscreen, bool isVsync) {
    gfxWidth = Def::SCREEN_WIDTH;
    gfxHeight = Def::SCREEN_HEIGHT;
    vsyncEnabled = isVsync;
    
    Uint32 windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    if (isFullscreen) {
        windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }

    setOpenGlAttributes();
    createWindow(windowFlags);
    createOpenGlContext();
    setVsyncEnabled(isVsync);

    SDL_GL_MakeCurrent(sdlWindow, glContext);

    // Enable blending and depth testing for proper rendering
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(0, 0, gfxWidth, gfxHeight);
}

void Window::setTitle(const std::string& title) {
    this->title = title;
    SDL_SetWindowTitle(sdlWindow, title.c_str());
}

SDL_Window* Window::getWindow() const {
    return sdlWindow;
}

SDL_GLContext Window::getGlContext() const {
    return glContext;
}

float Window::getAspectRatio() const {
    return static_cast<float>(gfxWidth) / static_cast<float>(gfxHeight);
}

std::pair<int, int> Window::getWindowSize() const {
    return { gfxWidth, gfxHeight };
}

void Window::createWindow(Uint32 windowFlags) {
    title = Def::NAME;
    sdlWindow = SDL_CreateWindow(
        Def::NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        gfxWidth,
        gfxHeight,
        windowFlags
    );

    if (sdlWindow == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    setIcon();
}

void Window::createOpenGlContext() {
    glContext = SDL_GL_CreateContext(sdlWindow);
    if (glContext == nullptr) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(sdlWindow);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    initGlad();
}

void Window::initGlad() {
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(sdlWindow);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void Window::setOpenGlAttributes() {
    // Request at 32-bit color
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    // Request a double-buffered, OpenGL 4.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void Window::setIcon() {
    std::string icon = "./data/images/icon.png";
    SDL_Surface* iconSurface = IMG_Load(icon.c_str());
    SDL_SetWindowIcon(sdlWindow, iconSurface);
    SDL_FreeSurface(iconSurface);
}

void Window::setVsyncEnabled(bool isVsync) {
    vsyncEnabled = isVsync;
    SDL_GL_SetSwapInterval(isVsync ? 1 : 0);
}

std::string Window::getTitle() const {
    return title;
}
