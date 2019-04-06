#ifndef GAME_H
#define GAME_H
#include <string>
#include "State.h"
using namespace std;

class State;
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