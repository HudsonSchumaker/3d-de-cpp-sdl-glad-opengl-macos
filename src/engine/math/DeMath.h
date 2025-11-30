    /**
* @file DeMath.hpp
* @author Hudson Schumaker
* @brief Defines and implements the DeMath class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

class DeMath final {
public:
    inline static float normalizeAngle(float angle) {
        angle = std::remainder(angle, Def::TWO_PI);
        if (angle < 0) {
            angle = Def::TWO_PI + angle;
        } 
            return angle;
    }

    inline static float deg2Rad(float angle) {
        return angle * Def::DEG2RAD;
    }

    inline static float rad2Deg(float angle) {
        return angle * Def::RAD2DEG;
    }
};
