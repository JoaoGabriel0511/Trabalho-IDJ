#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define SPACE_KEY SDLK_SPACE
#define A_KEY SDLK_a
#define W_KEY SDLK_w
#define D_KEY SDLK_d
#define S_KEY SDLK_s
#include "SDL2/SDL.h"
#include <iostream>
#include "Debugger.h"

class InputManager {
    bool mouseState[6];
    int mouseUpdate[6];
    bool quitRequested;
    int updateCounter;
    int mouseX;
    int mouseY;
    bool keyState[416];
    int keyUpdate[416];
    public:
        void Update();
        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool MouseRelease(int button);
        bool MousePress(int button);
        bool IsMouseDown(int button);
        bool IsKeyDown(int key);
        int GetMouseX();
        int GetMouseY();
        bool QuitRequested();
        static InputManager& GetInstance();
        InputManager();
        ~InputManager();
};

#endif