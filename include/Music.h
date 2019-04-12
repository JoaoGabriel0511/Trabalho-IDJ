#ifndef MUSIC_H
#define MUSIC_H
#include "SDL2/SDL.h"
#include "Resources.h"
#include "GameObject.h"
using namespace std;
class Music : public Component{
    Mix_Music * music;
    public:
        Music(GameObject& associated);
        Music(GameObject& associated, string file);
        ~Music();
        void Play(int times);
        void Stop(int msToStop);
        void Open(string file);
        bool IsOpen();
        void Update(float dt);
        bool Is(string type);
        void Render();
};
#endif