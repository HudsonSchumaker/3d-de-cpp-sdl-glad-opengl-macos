/**
* @file Pch.h
* @author Hudson Schumaker
* @brief Pch includes and definitions for the Dodoi-Engine.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
// C++ includes
#include <set>
#include <map>
#include <list>
#include <array>
#include <cmath>
#include <chrono>
#include <future>
#include <limits>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>
#include <variant>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <typeindex>
#include <filesystem>
#include <functional>
#include <unordered_map>
#include <unordered_set>

// ARM NEON includes
//#include <arm_neon.h>

// OpenGL includes
#include <glad/glad.h>

// SDL2 includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_gamecontroller.h>

// Dodoi-Engine folders
#define MAP_FOLDER "./data/maps/"
#define OBJ_FOLDER "./data/models/"
#define FONT_FOLDER "./data/fonts/"
#define AUDIO_FOLDER "./data/audios/"
#define IMAGE_FOLDER "./data/images/"
#define SHADER_FOLDER "./data/shaders/"
#define SHADER_FOLDER_BINARY "./data/bin/"

class Def final {
public:
    inline static const char NAME[] = "Dodoi Engine v.0.0.0-macOS";

    constexpr static float FPS = 180.0f;
    constexpr static float TARGET_FRAME_TIME = 1.0f / FPS; // seconds per frame
	
    constexpr static const float PI = 3.14159265358979323846f;
    constexpr static const float TWO_PI = 2.0f * PI;
    constexpr static const float HALF_PI = PI / 2.0f;
    constexpr static const float DEG2RAD = PI / 180.0f;
    constexpr static const float RAD2DEG = 180.0f / PI;

    static const int SCREEN_WIDTH = 1280;
    static const int SCREEN_H_WIDTH = SCREEN_WIDTH / 2;
    static const int SCREEN_HEIGHT = 720;
    static const int SCREEN_H_HEIGHT = SCREEN_HEIGHT / 2; 
};
