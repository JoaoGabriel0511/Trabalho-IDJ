#include "../include/State.h"
#include "../include/Sprite.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
State::State() {
    quitRequested = false;
    //bg* = new Sprite();
}

void State::Update(float dt) {
    while(SDL_QuitRequested() == true) {
        quitRequested = true;
    }
}

void State::Render() {

}

bool State::QuitRequested() {
    quitRequested = false;
    return quitRequested;
}
