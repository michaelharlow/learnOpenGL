//
// Created by micha on 3/24/2022.
//

#ifndef LEARNOPENGL_COMPONENTS_H
#define LEARNOPENGL_COMPONENTS_H

#include <bitset>
#include <vector>

typedef unsigned long long EntityID;
const int MAX_COMPONENTS = 32;
typedef std::bitset <MAX_COMPONENTS> ComponentMask;

int s_componentCounter;
template<class T> int getID() {
    static int s_componentID = s_componentCounter++;
    return s_componentID;
}

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

    template<class T> void assign(EntityID id) {
        int componentID = getID<T>();
        entities[id].mask.set(componentID);
    }

    std::vector<Entity> entities;
};

struct ComponentPool
{

};


#endif //LEARNOPENGL_COMPONENTS_H
