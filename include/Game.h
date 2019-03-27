#ifndef GAME_H
#define GAME_H
#include <string>
#include "State.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
using namespace std;

class Game {
    Game(string title, int width, int height);
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;
    static Game *instance;
    public:
        ~Game();
        void Run();
        SDL_Renderer * GetRenderer();
        State& GetState();
        static Game& GetInstance();

};
#endif