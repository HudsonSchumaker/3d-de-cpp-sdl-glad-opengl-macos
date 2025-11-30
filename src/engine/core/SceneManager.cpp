/**
* @file SceneManager.cpp
* @author Hudson Schumaker
* @brief Implements the SceneManager class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "SceneManager.h"
#include "Window.h"

SceneManager* SceneManager::getInstance() {
    if (instance == nullptr) {
        instance = new SceneManager();
    }
    return instance;
}

void SceneManager::addScene(const std::string& sceneName, std::unique_ptr<Scene> scene) {
    scenes[sceneName] = std::move(scene);
}

void SceneManager::displayLoadingScreen() {
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f); // Blue background
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(Window::getInstance()->getWindow());
}

void SceneManager::loadSceneAsync(const std::string& sceneName) {
    auto it = scenes.find(sceneName);
    if (it != scenes.end()) {
        displayLoadingScreen();
        it->second->loadAsync();
        it->second->waitForLoad();
        auto exitCode = it->second->run();

        if (exitCode != 0) {
           return;
        }

        it->second->setIsLoaded(false);
        auto nextSceneName = it->second->getNextSceneName();
        if (!nextSceneName.empty() && nextSceneName != notFoundScene) {
            loadSceneAsync(nextSceneName);
        }

    } else {
        std::cerr << "Scene '" << sceneName << "' not found!" << std::endl;
    }
}

const std::string& SceneManager::getCurrentSceneName() const {
    for (const auto& pair : scenes) {
        if (pair.second->getIsLoaded()) {
            return pair.first;
        }
    }
    return notFoundScene;
}

const std::string& SceneManager::getNextSceneName() const {
    for (const auto& pair : scenes) {
        if (pair.second->getIsLoaded()) {
            return pair.second->getNextSceneName();
        }
    }
    return notFoundScene;
}
