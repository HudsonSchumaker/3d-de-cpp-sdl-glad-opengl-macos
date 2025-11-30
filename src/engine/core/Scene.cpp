/**
* @file Scene.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Scene.h"
#include "Window.h"

void Scene::loadAsync() {
    loadFuture = std::async(std::launch::async, &Scene::load, this);
}

void Scene::updateDeltaTime() {
    time->update();
}

void Scene::waitForLoad() {
    if (loadFuture.valid()) {
        loadFuture.get();
        isLoaded = true;
    }
}

const std::string& Scene::getNextSceneName() const {
    return nextScene;
}

void Scene::setIsLoaded(bool loaded) {
    isLoaded = loaded;
}

bool Scene::getIsLoaded() const {
    return isLoaded;
}

void Scene::beginRender() {
    glClearColor(background.r, background.g, background.b, background.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::endRender() {
    SDL_GL_SwapWindow(Window::getInstance()->getWindow());
}
