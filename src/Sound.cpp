#include "../include/Sound.h"
using namespace std;

Sound::Sound(GameObject& associated) : Component(associated){
    this->associated = associated;
    chunk = NULL;
    chanel = NULL;
}

Sound::Sound(GameObject& associated, string file) : Sound(associated) {
    Open(file);
}

void Sound::Play(int times = 1) {
    int i = 0;
    chanel = Mix_PlayChannel(-1, chunk, times-1);
    if (chanel == NULL){
        cout << "Nenhum canal disponivel para o som" << endl;
    }
}

void Sound::Stop() {
    if(chanel != NULL){
        Mix_HaltChannel(chanel);
    } else {
        cout << "som nao esta tocando" << endl;
    }
}

void Sound::Open(string file) {
    chunk = Resources::GetSound(file);
    if(chunk == NULL) {
        cout << "falha em abrir o som" << file << endl;
    }
}

Sound::~Sound() {}

void Sound::Update(float dt){

}
void Sound::Render(){

}

bool Sound::Is(string type){
    bool result = false;
    if(type == "Sound") {
        result = true;
    }
    return result;
}

