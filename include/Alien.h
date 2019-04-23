#ifndef ALIEN_H
#define ALIEN_H
#include "Component.h"
#include "Action.h"
#include "Debugger.h"
#include "Sprite.h"
#include <queue>
    class Alien : public Component {
        Action *action;
        Vect2 speed;
        int hp;
        bool isNewAction;
        queue<Action> taskQueue;
        vector<weak_ptr<GameObject>> minionArray;
        public:
            Alien(GameObject& associated, int nMinions);
            ~Alien();
            void Start();
            void Update(float dt);
            void Render();
            bool Is(string type);
    };

#endif