#include "../include/Face.h"
using namespace std;
bool Face::deletedFace = false;
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

void Face::SetDeleted(bool deleted) {
    Face::deletedFace = deleted;
}

void Face::Update(float dt) {
    InputManager inputManager = InputManager::GetInstance();
    if(deletedFace == false) {
        if(inputManager.MousePress(LEFT_MOUSE_BUTTON) && associated.box.Contains(inputManager.GetMouseX(), inputManager.GetMouseY()) ) {
            cout << "CLICKOU NO PINGUIN" << endl;
            // Aplica dano
            Damage(30);
            // Sai do loop (só queremos acertar um)
            deletedFace = true;
        }
    }
}

void Face::Render() {
    associated.box.x += Camera::speed.x;
    associated.box.y += Camera::speed.y;
}

bool Face::Is(string type)  {
    bool result = false;
    if(type == "Face") {
        result = true;
    }
    return result;
}

Face::~Face() {}