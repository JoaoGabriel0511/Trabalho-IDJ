#include "../include/Face.h"
using namespace std;

Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage) {
    hitpoints = hitpoints - damage;
    if(hitpoints <= 0) {
        cout << "hitpoints acabou"<< endl;
        associated.RequestedDelete();
    }
}

void Face::Update(float dt) {}

void Face::Render() {}

bool Face::Is(string type)  {
    bool result = false;
    if(type == "Face") {
        result = true;
    }
    return result;
}

Face::~Face() {}