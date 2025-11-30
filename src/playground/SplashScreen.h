/**
* @file SplashScreen.h
* @author Hudson Schumaker
* @brief Defines the SplashScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2025, Dodoi-Lab
*/
#pragma once
#include "../core/Scene.h"

class SplashScreen final : public Scene {
private:
	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	SplashScreen();
	~SplashScreen();

	short run() override;
};
