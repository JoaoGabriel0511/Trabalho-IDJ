#ifndef ALIEN_H
#define ALIEN_H
#include "Action.h"
#include "Game.h"
#include "Minion.h"
#include "Debugger.h"
#include <queue>
#include <cmath>
    class Alien : public Component {
        Action action;
        Vect2 direction;
        Vect2 start;
        Vect2 goPos;
        Vect2 end;
        float distance;
        float hipspeed;
        int hp;
        bool isNewAction;
        void MoveAlien(float dt);
        void ShootBullet(float dt);
        void AddMinion(int arc);
        float rotationSpeed;
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