/**
* @file EcsManager.h
* @author Hudson Schumaker
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../../Pch.h"
#include "Entity.h"
#include "ComponentArray.h"

class EcsManager final {
private:
    inline static EcsManager* instance = nullptr;
    std::vector<Entity> entities;
    std::unordered_map<std::type_index, std::shared_ptr<IComponentArray>> components;

    EcsManager() = default;

    template<typename T>
    std::shared_ptr<ComponentArray<T>> getComponentArray() {
        auto type = std::type_index(typeid(T));
        if (components.find(type) == components.end()) {
            components[type] = std::make_shared<ComponentArray<T>>();
        }
        return std::static_pointer_cast<ComponentArray<T>>(components[type]);
    }
public:
    ~EcsManager();   

    static EcsManager* getInstance();
    Entity newEntity();
    void destroyEntity(Entity entity);

    template<typename T>
    void addComponent(Entity entity, T component) {
        getComponentArray<T>()->insert(entity, component);
    }
    
    template<typename T>
    void removeComponent(Entity entity) {
        getComponentArray<T>()->remove(entity);
    }
    
    template<typename T>
    T& getComponent(Entity entity) {
        return getComponentArray<T>()->get(entity);
    }
    
    template<typename T>
    bool hasComponent(Entity entity) {
        return getComponentArray<T>()->has(entity);
    }
    
    template<typename... Components>
    std::vector<Entity> getEntitiesWith() {
        std::vector<Entity> result;
        for (Entity entity : entities) {
            if ((hasComponent<Components>(entity) && ...)) {
                if (entity.active) {
                    result.push_back(entity);
                }
            }
        }
        return result;
    }
    
    const std::vector<Entity>& getAllEntities() const { return entities; }

};
