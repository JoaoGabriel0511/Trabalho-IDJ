#include "../include/Resources.h"
using namespace std;
unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;
SDL_Texture * Resources::GetImage(string file) {
    SDL_Texture * texture;
    if(imageTable.find(file) == imageTable.end()){
        texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
        if(texture == NULL){
            cout<<"Falha ao carregar imagem "<<file<<" no hash de imagens"<<endl;
        } else {
            pair<string, SDL_Texture*> newTexture(file, texture);
            imageTable.insert(newTexture);
            return texture;
        }
    } else {
        return imageTable[file];
    }
}

void Resources::ClearImages() {
    for(auto texture = imageTable.begin(); texture != imageTable.end(); texture++) {
        SDL_DestroyTexture(texture->second);
    }
    imageTable.clear();
}

Mix_Music * Resources::GetMusic(string file) {
    Mix_Music * music;
    if(musicTable.find(file) == musicTable.end()){
        music = Mix_LoadMUS(file.c_str());
        if(music == NULL){
            cout<<"Falha ao carregar imagem "<<file<<" no hash de imagens"<<endl;
        } else {
            pair<string, Mix_Music*> newMusic(file, music);
            musicTable.insert(newMusic);
            return music;
        }
    } else {
        return musicTable[file];
    }
}

void Resources::ClearMusics() {
    for(auto music = musicTable.begin(); music != musicTable.end(); music++) {
        Mix_FreeMusic(music->second);
    }
    musicTable.clear();
}

Mix_Chunk * Resources::GetSound(string file) {
    Mix_Chunk * sound;
    if(soundTable.find(file) == soundTable.end()){
        sound = Mix_LoadWAV(file.c_str());
        if(sound == NULL){
            cout<<"Falha ao carregar imagem "<<file<<" no hash de imagens"<<endl;
        } else {
            pair<string, Mix_Chunk*> newsound(file, sound);
            soundTable.insert(newsound);
            return sound;
        }
    } else {
        return soundTable[file];
    }
}

void Resources::ClearSounds() {
    for(auto sound = soundTable.begin(); sound != soundTable.end(); sound++) {
        if(sound->second != NULL) {
            Mix_FreeChunk(sound->second);
        }
    }
    soundTable.clear();
}