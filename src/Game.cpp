#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <string>
#include <fstream>
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
        instance = new Game("trabalho1", 800, 600);
        return *instance;
    }
}

float Game::GetDeltaTime() {
    return dt;
}

void Game::CalculateDeltaTime() {
    dt = SDL_GetTicks() - frameStart;
    dt = dt/1000;
    frameStart = SDL_GetTicks();
}

Game::Game(string title, int width, int height) {
    if (instance != NULL){
        throw runtime_error("so deveria ter um objeto instanciado");
    }
    frameStart = 0;
    dt = 0;
    instance = this;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MP3);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(32);
    Mix_HaltChannel(1);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    cout<< "CRIANDO STATE DO JOGO..." <<endl;
    this->state = new State();
    cout<< "STATE DO JOGO CRIADO"<<endl;
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
    int i = 1;
    cout << "Comencando o loop do Jogo..." << endl;
    Debugger debugger = Debugger::GetInstance();
    state->Start();
    while(state->QuitRequested() == false) {
        CalculateDeltaTime();
        if(debugger.lookLoopGame) {
            cout<<"COMECANDO LOOP "<< i << " DO JOGO..."<<endl;
            cout<< "COMECANDO O UPDATE DO STATE..." <<endl;
        }
        InputManager::GetInstance().Update();
        if(debugger.lookLoopGame) {
            cout<<"CONSEGUIU O INSTANCE DO INPUT MANAGE"<<endl;
        }
        state->Update(GetDeltaTime());
        if(debugger.lookLoopGame) {
            cout<< "UPDATE DE STATE FEITO" <<endl;
            cout<< "COMECANDO RENDER DO STATE..." <<endl;
        }
        state->Render();
        if(debugger.lookLoopGame) {
            cout<< "RENDER DE STATE FEITO" <<endl;
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(11);
        i++;
        if(debugger.lookLoopGame) {
            cout<<"LOOP "<< i << " DO JOGO FINALIZADO"<<endl;
        }
    }
}