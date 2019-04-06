#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include "SDL2/SDL.h"
#include "Component.h"
#include "Game.h"
#include "Vect2.h"
#include "SDL2/SDL_image.h"
using namespace std;
class Sprite : public Component {
    SDL_Texture * texture;
    int width;
    int height;
    SDL_Rect clipRect;
    public:
        Sprite(GameObject &associated);
        Sprite(GameObject &associated, string file);
        ~Sprite();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        void Update(float dt);
        bool Is(string type);
};
#endif