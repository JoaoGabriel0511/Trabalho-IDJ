#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <string>
#include "../include/Game.h"
#include "../include/Sprite.h"
#include "../include/State.h"
#include "../include/Music.h"
#include <iostream>
using namespace std;

Game* Game::instance;

Game& Game::GetInstance() {
    if(instance != NULL) {
        return *instance;
    } else {
        instance = new Game("trabalho1", 600, 1000);
        return *instance;
    }
}

Game::Game(string title, int width, int height) {
    if (instance != NULL){
        throw runtime_error("so deveria ter um objeto instanciado");
    }
    instance = this;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MP3);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(32);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    this->state = new State();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState() {
    return * state;
}

SDL_Renderer * Game::GetRenderer () {
    return renderer;
}

void Game::Run() {
    while(state->QuitRequested() == false) {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}
