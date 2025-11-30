/**
* @file EcsManager.cpp
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "EcsManager.h"
#include "../component/Transform.h"

EcsManager* EcsManager::getInstance() {
    if (instance == nullptr) {
        instance = new EcsManager();
    }
    return instance;
}

EcsManager::~EcsManager() {
    entities.clear();
}

Entity EcsManager::newEntity() {
    if (entities.size() >= Entity::MAX_ENTITIES) {
        throw std::runtime_error("Maximum number of entities reached");
    }
    Entity entity;
    entities.push_back(entity);
    addComponent<Transform>(entity, Transform());

    return entity;
}

void EcsManager::destroyEntity(Entity entity) {
    for (auto& [type, componentArray] : components) {
        if (componentArray->has(entity)) {
            componentArray->remove(entity);
        }
    }

    entities.erase(std::remove_if(entities.begin(), entities.end(),
        [&entity](const Entity& e) { return e.getId() == entity.getId(); }),
        entities.end());
}
