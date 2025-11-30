/**
* @file SceneManager.h
* @author Hudson Schumaker
* @version 1.1.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "Scene.h"

class SceneManager final{
private:
    inline static SceneManager* instance = nullptr;
    std::map<std::string, std::unique_ptr<Scene>> scenes;
    std::string notFoundScene = "404";

    SceneManager() = default;
    void displayLoadingScreen();

public:
    ~SceneManager() = default;

    static SceneManager* getInstance();
    void addScene(const std::string& sceneName, std::unique_ptr<Scene> scene);
    void loadSceneAsync(const std::string& sceneName);
    const std::string& getCurrentSceneName() const;
    const std::string& getNextSceneName() const;
};
