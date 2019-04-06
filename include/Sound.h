#ifndef Sound_H
#define Sound_H
#include "SDL2/SDL_mixer.h"
#include "Component.h"
using namespace std;
class Sound : public Component {
    Mix_Chunk *chunk;
    public:
        Sound(GameObject& associated);
        Sound(GameObject& associated, string file);
        ~Sound();
        void Play(int times);
        void Stop();
        void Open(string file);
        bool IsOpen();
        void Update(float dt);
        void Render();
        bool Is(string type);
        int chanel;
};

#endif