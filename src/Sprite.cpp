#include "../include/Sprite.h"
using namespace std;

Sprite::Sprite(GameObject &associated) : Component(associated) {
    texture = NULL;
    scale.x = 1;
    scale.y = 1;
}

Sprite::Sprite(GameObject &associated, string file) : Component(associated) {
    texture = NULL;
    scale.x = 1;
    scale.y = 1;
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

Sprite::~Sprite() {}

bool Sprite::Open(string file) {
    texture = Resources::GetImage(file);
    if(texture == NULL){
        cout << "ERROR CRASHOU: Sprite.Open IMG_LoadTexture"<<endl;
        cout << SDL_GetError() << endl;
        return false;
    } else {
        cout << "Imagem "<< file <<" do sprite carregada" << endl;
        SDL_QueryTexture(texture, NULL, NULL, &associated.box.w, &associated.box.h);
        SetClip(0, 0, associated.box.w, associated.box.h);
        return true;
    }
}

void Sprite::SetScaleX(float scalex, float scaley) {
    if(scalex > 0) {
        scale.x = scalex;
    }
    if(scaley > 0) {
        scale.y = scaley;
    }
    associated.box.x = associated.box.x - (((scalex-1) * associated.box.x)/2);
    associated.box.y = associated.box.y - (((scaley-1) * associated.box.y)/2);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Render() {
    Render(associated.box.x + Camera::pos.x, associated.box.y + Camera::pos.y, associated.box.w, associated.box.h);
}

void Sprite::Render(float x, float y, float w, float h) {
    SDL_Rect dstRect{ int(x), int(y), w*scale.y, h*scale.y };
    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect, associated.angleDeg, NULL, SDL_FLIP_NONE);
}

int Sprite::GetHeight() {
    return associated.box.h;
}

int Sprite::GetWidth() {
    return associated.box.w;
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