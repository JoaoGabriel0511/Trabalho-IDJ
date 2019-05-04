#ifndef MINION_H
#define MINION_H

#include "Component.h"
#include "Sprite.h"
#include "Bullet.h"

class Minion : public Component {
    float arc;
    float arcSpeed;
    GameObject& alienCenter;
    public:
        Minion(GameObject& associated, GameObject& alienCenter, float arcOffsetDeg = 0);
        void Update(float dt);
        void Render();
        bool Is(string type);
        void Shoot(Vect2 direction);
};


#endif