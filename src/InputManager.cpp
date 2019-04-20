#include "../include/InputManager.h"
#include "unistd.h"
using namespace std;
InputManager& InputManager::GetInstance() {
    static InputManager inputManager;
    return inputManager;
}

InputManager::~InputManager() {}

InputManager::InputManager() {
    for(int i = 0; i < 416; i++){
        keyState[i] = 0;
        keyUpdate[i] = 0;
    }
    for(int j = 0; j < 6; j++) {
        mouseState[j] = 0;
        mouseUpdate[j] = 0;
    }
    updateCounter = 0;
    quitRequested = 0;
    mouseX = 0;
    mouseY = 0;
}

void InputManager::Update() {
    SDL_Event * event = new SDL_Event();
    updateCounter++;
    Debugger debugger = Debugger::GetInstance();
    if(SDL_PollEvent(event)){
        switch (event->type) {
            case SDL_QUIT:
                if(debugger.lookInputManager){
                    cout<<"Saida requisitada"<<endl;
                }
                quitRequested = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(debugger.lookInputManager) {
                    cout<<"SDL_MOUSEDOWN"<<endl;
                }
                mouseState[event->button.button] = true;
                mouseUpdate[event->button.button] = updateCounter;
                break;
            case SDL_MOUSEBUTTONUP:
                if(debugger.lookInputManager) {
                    cout<<"SDL_MOUSEUP"<<endl;
                }
                mouseState[event->button.button] = false;
                mouseUpdate[event->button.button] = updateCounter;
                break;
            case SDL_KEYUP:
                if(debugger.lookInputManager) {
                    cout<<"SDL_KEYUP"<<endl;
                }
                if(event->key.keysym.sym < 416){
                    if(debugger.lookInputManager) {
                        cout<<"KEY lida: "<<event->key.keysym.sym<<endl;
                    }
                    keyState[event->key.keysym.sym] = false;
                    keyUpdate[event->key.keysym.sym] = updateCounter;
                } else {
                    int pos = event->key.keysym.sym - 0x3FFFFF81;
                    if(debugger.lookInputManager) {
                        cout<<"KEY lida: "<<pos<<endl;
                    }
                    keyState[pos] = true;
                    keyUpdate[pos] = updateCounter;
                }
                break;
            case SDL_KEYDOWN:
                if(debugger.lookInputManager) {
                    cout<<"SDL_KEYDOWN"<<endl;
                }
                if(event->key.repeat != 1) {
                    if(event->key.keysym.sym < 416){
                        if(debugger.lookInputManager) {
                            cout<<"KEY lida: "<<event->key.keysym.sym<<endl;
                        }
                        keyState[event->key.keysym.sym] = true;
                        keyUpdate[event->key.keysym.sym] = updateCounter;
                    } else {
                        int pos = event->key.keysym.sym - 0x3FFFFF81;
                        if(debugger.lookInputManager) {
                            cout<<"KEY lida: "<<pos<<endl;
                        }
                        keyState[pos] = true;
                        keyUpdate[pos] = updateCounter;
                    }
                }
                break;
            default:
                break;
        }
    } else {
        if(debugger.lookInputManager){
            cout<<"Nenhum evento detectado"<<endl;
        }
    }
    SDL_GetMouseState(&mouseX, &mouseY);
}

bool InputManager::KeyPress(int key) {
    bool result = false;
    if(key >= 416) {
        key = key - 0x3FFFFF81;
    }
    if(keyState[key] == true) {
        if(keyUpdate[key] == updateCounter) {
            result = true;
        }
    }
    return result;
}

bool InputManager::KeyRelease(int key) {
    bool result = false;
    if(key >= 416) {
        key = key - 0x3FFFFF81;
    }
    if (keyState[key] == false) {
        if(keyUpdate[key] == updateCounter) {
            result = true;
        }
    }
    return result;
}

bool InputManager::MousePress(int button) {
    bool result = false;
    if(mouseState[button] == true) {
        if(mouseUpdate[button] == updateCounter) {
            result = true;
        }
    }
    return result;
}

bool InputManager::MouseRelease(int button) {
    bool result = false;
    if (mouseState[button] == false) {
        if(mouseUpdate[button] == updateCounter) {
            result = true;
        }
    }
    return result;
}

bool InputManager::IsMouseDown(int button) {
    bool result = false;
    if(mouseState[button] == true) {
        result = true;
    }
    return result;
}

bool InputManager::IsKeyDown(int key) {
    bool result = false;
    if(key >= 416) {
        key = key - 0x3FFFFF81;
    }
    if(keyState[key] == true) {
        result = true;
    }
    return result;
}

int InputManager::GetMouseX() {
    return mouseX;
}

int InputManager::GetMouseY() {
    return mouseY;
}

bool InputManager::QuitRequested() {
    return quitRequested;
}