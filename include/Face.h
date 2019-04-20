#ifndef FACE_H
#define FACE_H
#include "SDL2/SDL.h"
#include "Component.h"
using namespace std;

class Face : public Component {
    int hitpoints;
    static bool deletedFace;
    public:
        static void SetDeleted(bool deleted);
        Face(GameObject& associated);
        ~Face();
        void Damage(int damage);
        void Render();
        bool Is(string type);
        void Update(float dt);
};
#endif