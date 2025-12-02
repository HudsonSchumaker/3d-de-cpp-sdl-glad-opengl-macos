/**
* @file ShaderSource.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"

const std::string VERTEX_DEFAULT = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec2 aTexCoord;
        
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
        
    out vec2 TexCoord;
        
    void main() {
        gl_Position = projection * view * model * vec4(aPos, 1.0);
        TexCoord = aTexCoord;
    }
)";

const std::string FRAGMENT_DEFAULT = R"(
    #version 410 core
    out vec4 FragColor;
        
    in vec2 TexCoord;
        
    uniform sampler2D texture1;
        
    void main() {
        FragColor = texture(texture1, TexCoord);
    }
)";
