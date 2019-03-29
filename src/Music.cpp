#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include "../include/Music.h"
#include <iostream>
using namespace std;

Music::Music(){
    music = NULL;
}

Music::Music(string file){
    Open(file);
}

void Music::Play(int times = -1) {
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop = 1500) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file) {
    music = Mix_LoadMUS(file.c_str());
    if(music == NULL) {
        cout << "ERROR CRASHOU: Music"<<endl;
        cout << SDL_GetError() << endl;
    }
}

Music::~Music() {
    Mix_FreeMusic(music);
}