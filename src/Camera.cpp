#include "../include/Camera.h"
using namespace std;

GameObject * Camera::focus;
Vect2 Camera::pos;
Vect2 Camera::speed;

void Camera::Follow(GameObject * focus){
    Camera::focus = focus;
}

void Camera::UnFollow() {
    Camera::focus = NULL;
}

void Camera::Update(float dt) {
    InputManager inputManager = InputManager::GetInstance();
    if(focus == NULL) {
        if(inputManager.IsKeyDown(W_KEY)) {
            speed.x = 0;
            speed.y = 500 * dt;
        }
        if(inputManager.IsKeyDown(D_KEY)) {
            speed.x = -500 * dt;
            speed.y = 0;
        }
        if(inputManager.IsKeyDown(A_KEY)) {
            speed.x = 500 * dt;
            speed.y = 0;
        }
        if(inputManager.IsKeyDown(S_KEY)) {
            speed.x = 0;
            speed.y = -500 * dt;
        }
        if(inputManager.KeyRelease(W_KEY)) {
            speed.x = 0;
            speed.y = 0;
        }
        if(inputManager.KeyRelease(D_KEY)) {
            speed.x = 0;
            speed.y = 0;
        }
        if(inputManager.KeyRelease(A_KEY)) {
            speed.x = 0;
            speed.y = 0;
        }
        if(inputManager.KeyRelease(S_KEY)) {
            speed.x = 0;
            speed.y = 0;
        }
        pos = pos + speed;
    } else {
        pos.x = focus->box.x;
        pos.y = focus->box.y;
    }
}