#ifndef COMPONENT_H
#define COMPONENT_H
#include "SDL2/SDL.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Camera.h"
#include <string>
using namespace std;
class GameObject;
class Component {
    public:
        Component(GameObject &associated);
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual bool Is(string type) = 0;
        virtual ~Component();
    protected:
        GameObject& associated;
};
#endif


