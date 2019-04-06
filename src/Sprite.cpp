#include "../include/Sprite.h"

using namespace std;
Sprite::Sprite(GameObject &associated) : Component(associated) {
    texture = NULL;
}

Sprite::Sprite(GameObject &associated, string file) : Component(associated) {
    texture = NULL;
    this->Open(file);
}

void Sprite::Update(float dt) {}


bool Sprite::Is(string type) {
    bool result = false;
    if(type == "Sprite") {
        result = true;
    }
    return result;
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
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
        SetClip(0, 0, width, height);
    }
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Render() {
    SDL_Rect dstRect{ int(associated.box.x), int(associated.box.y), width, height };
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