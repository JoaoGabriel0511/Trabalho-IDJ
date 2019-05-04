#ifndef SPRITE_H
#define SPRITE_H
#include "SDL2/SDL.h"
#include "Component.h"
#include "Game.h"
#include "Vect2.h"
#include "Resources.h"
using namespace std;
class Sprite : public Component {
    SDL_Texture * texture;
    SDL_Rect clipRect;
    Vect2 scale;
    public:
        Sprite();
        Sprite(GameObject &associated);
        Sprite(GameObject &associated, string file);
        ~Sprite();
        bool Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        void Render(float x, float y, float w, float h);
        int GetWidth();
        int GetHeight();
        void SetScaleX(float scalex, float scaley);
        Vect2 GetScale();
        bool IsOpen();
        void Update(float dt);
        bool Is(string type);
};
#endif