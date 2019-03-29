#include "../include/State.h"
#include "../include/Sprite.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>
using namespace std;
State::State() {
    quitRequested = false;
    LoadAssets();
    this->music->Play(-1);
}

void State::Update(float dt) {
    if(SDL_QuitRequested() == true) {
        quitRequested = true;
    }
}

void State::Render() {
    bg->Render(0, 0);
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets(){
    bg = new Sprite("assets/img/ocean.jpg");
    music = new Music("assets/audio/stageState.ogg");
}
