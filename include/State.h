#ifndef STATE_H
#define STATE_H
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Sound.h"
#include "TileMap.h"
#include "CameraFollower.h"
#include "Debugger.h"
#include "Alien.h"
#include <vector>
#include <memory>
using namespace std;
class tileMap;
class State {
    GameObject *bg;
    bool quitRequested;
    vector<shared_ptr<GameObject>> objectArray;
    //void Input();
    bool started;
    void AddPenguin();
    public:
        weak_ptr<GameObject> AddObject(int mouseX, int mouseY);
        weak_ptr<GameObject> GetObjectPtr(GameObject *go);
        void Start();
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};
#endif