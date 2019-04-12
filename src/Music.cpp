#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "../include/Music.h"
#include <iostream>
using namespace std;

Music::Music(GameObject& associated) : Component(associated){
    music = NULL;
}

Music::Music(GameObject& associated, string file) : Component(associated) {
    Open(file);
}

void Music::Play(int times = -1) {
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop = 1500) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
    music = Resources::GetMusic(file);
    if(music == NULL) {
        cout << "ERROR CRASHOU: Music"<<endl;
        cout << SDL_GetError() << endl;
    }
}

Music::~Music() {}

void Music::Update(float dt) {}

void Music::Render() {}

bool Music::Is(string type){
    bool result = false;
    if(strcmp("Music", type.c_str()) == 0){
        result = true;
    }
    return result;
}