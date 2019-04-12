#ifndef STATE_H
#define STATE_H
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Sound.h"
#include "TileMap.h"
#include <vector>
#include <memory>
using namespace std;
class tileMap;
class State {
    GameObject *bg;
    bool quitRequested;
    vector<unique_ptr<GameObject>> objectArray;
    void Input();
    void AddObject(int mouseX, int mouseY);
    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};
#endif