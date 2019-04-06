#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL2/SDL.h"
#include "Component.h"
#include "Rect.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Component;
class GameObject{
    bool isDead;
    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestedDelete();
        void AddComponent(shared_ptr<Component> cpt);
        void RemoveComponent(shared_ptr<Component> cpt);
        shared_ptr<Component> GetComponent(string type);
        Rect box;
        vector<shared_ptr<Component>> components;
};
#endif


