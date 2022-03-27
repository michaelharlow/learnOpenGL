//
// Created by micha on 3/24/2022.
//

#ifndef LEARNOPENGL_COMPONENTS_H
#define LEARNOPENGL_COMPONENTS_H

#include <bitset>
#include <vector>

typedef unsigned long long EntityID;
const int MAX_COMPONENTS = 32;
const int MAX_ENTITIES = 64;
typedef std::bitset <MAX_COMPONENTS> ComponentMask;

int s_componentCounter;
template<typename T> int getID() {
    static int s_componentID = s_componentCounter++;
    return s_componentID;
}

struct ComponentPool
{
    char* data{nullptr};
    size_t elementSize{0};

    ComponentPool(size_t elementSize) {
        this->elementSize = elementSize;
        data = new char[elementSize * MAX_ENTITIES];
    }

    ~ComponentPool() {
        delete[] data;
    }

    void* get(size_t index) {
        return data + (index * elementSize);
    }
};

struct Scene
{
    struct Entity
    {
        EntityID id;
        ComponentMask mask;
    };

    EntityID newEntity() {
        entities.push_back({entities.size(), ComponentMask()});
        return entities.back().id;
    }

    template<typename T> T* assign(EntityID id) {
        int componentID = getID<T>();

        if (componentPools.size() <= componentID) {
            componentPools.resize(componentID + 1, nullptr);
        }
        if (componentPools[componentID] == nullptr) {
            componentPools[componentID] = new ComponentPool(sizeof(T));
        }

        T* pComponent = new (componentPools[componentID]->get(id)) T();

        entities[id].mask.set(componentID);
        return pComponent;
    }

    template<typename T> T* get(EntityID id) {
        int componentID = getID<T>();

        if (!entities[id].mask.test(componentID)) {
            return nullptr;
        }

        T* pComponent = static_cast<T*>(componentPools[componentID]->get(id));
        return pComponent;
    }

    std::vector<Entity> entities;
    std::vector<ComponentPool*> componentPools;
};


#endif //LEARNOPENGL_COMPONENTS_H
