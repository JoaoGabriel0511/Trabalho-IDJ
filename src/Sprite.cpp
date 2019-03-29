#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "../include/Sprite.h"
#include "../include/Game.h"
using namespace std;
Sprite::Sprite() {
    texture = NULL;
}

Sprite::Sprite(string file){
    texture = NULL;
    this->Open(file);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
    if(texture != NULL) {
        SDL_DestroyTexture(texture);
    }
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == NULL){
        cout << "ERROR CRASHOU: Sprite.Open IMG_LoadTexture"<<endl;
        cout << SDL_GetError() << endl;
    } else {
        cout << "Deu certo" << endl;
        SDL_QueryTexture(texture, NULL, NULL, &height, &width);
        SetClip(0, 0, height, width);
    }
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Render(int x, int y) {
    SDL_Rect dstRect{ x, y, clipRect.w, clipRect.h };
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect);
}

int Sprite::GetHeight() {
    return height;
}

int Sprite::GetWidth() {
    return width;
}

bool Sprite::IsOpen(){
    bool isOpen;
    if(texture != NULL) {
        isOpen = true;
    } else {
        isOpen = false;
    }
    return isOpen;
}