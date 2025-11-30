/**
* @file Scene.h
* @author Hudson Schumaker
* @version 1.1.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "../gfx/Color.h"
#include "../core/Time.h"

class Scene {
private:
    Time* time = Time::getInstance();
    std::future<void> loadFuture;

    virtual void load() = 0;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void unload() = 0;

protected:
    Color background = { 0.0f, 0.0f, 0.0f, 0.0f };
    std::string nextScene = "404";

    bool isRunning = false;
    bool isPaused = false;
    bool isLoaded = false;
    short exit = 0;

    void beginRender();
    void endRender();

public:
    Scene() = default;
    virtual ~Scene() {}
    virtual short run() = 0;

    void updateDeltaTime();
    void setIsLoaded(bool loaded);
    void loadAsync();
    void waitForLoad();
    bool getIsLoaded() const;
    const std::string& getNextSceneName() const;
};
