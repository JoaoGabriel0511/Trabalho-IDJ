#ifndef MUSIC_H
#define MUSIC_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <string>
using namespace std;
class Music {
    Mix_Music * music;
    public:
        Music();
        Music(string file);
        ~Music();
        void Play(int times);
        void Stop(int msToStop);
        void Open(string file);
        bool IsOpen();
};
#endif