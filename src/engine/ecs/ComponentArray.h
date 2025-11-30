/**
* @file ComponentArray.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "Entity.h"

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void remove(Entity entity) = 0;
    virtual bool has(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
    std::unordered_map<u_int32_t, T> data;

public:
    ComponentArray() = default;
    ~ComponentArray() override {
        data.clear();
    };

    void insert(Entity entity, T component) {
        data[entity.getId()] = component;
    }

    void remove(Entity entity) override {
        data.erase(entity.getId());
    }

    T& get(Entity entity) {
        return data.at(entity.getId());
    }

    bool has(Entity entity) override {
        return data.find(entity.getId()) != data.end();
    }
};
