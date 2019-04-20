#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Vect2.h"
class GameObject;
class Camera {
    static GameObject * focus;
    public:
        static void Follow(GameObject * newFocus);
        static void UnFollow();
        static void Update(float dt);
        static Vect2 pos;
        static Vect2 speed;
};

#endif