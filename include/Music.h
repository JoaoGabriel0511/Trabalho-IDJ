#ifndef MUSIC_H
#define MUSIC_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
class Music {
    // MixMusic * music;
    public:
        Music();
        Music(const char * file);
        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(const char * file);
        bool IsOpen();
};
#endif