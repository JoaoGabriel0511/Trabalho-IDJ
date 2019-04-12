#ifndef RESOURCES_H
#define RESOURCES_H
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Game.h"
#include <unordered_map>
#include <string>
using namespace std;
class Resources {
    static unordered_map<string, SDL_Texture*> imageTable;
    static unordered_map<string, Mix_Music*> musicTable;
    static unordered_map<string, Mix_Chunk*> soundTable;
    public:
        static SDL_Texture * GetImage(string file);
        static void ClearImages();
        static Mix_Music * GetMusic(string file);
        static void ClearMusics();
        static Mix_Chunk * GetSound(string file);
        static void ClearSounds();
};

#endif
