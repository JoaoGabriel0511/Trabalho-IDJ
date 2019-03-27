#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "../include/Sprite.h"
Sprite::Sprite() {
    texture = NULL;
}

Sprite::Sprite(const char * file){
    texture = NULL;
    //Open();
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

/*void Sprite::Open(const char * file) {
    if(IMG_LoadTexture(Game::GetInstance(), file) == NULL){

    } else {
        SDL_QueryTexture(Game::GetInstance().texture, NULL, NULL, &width, &height);
    }
}*/