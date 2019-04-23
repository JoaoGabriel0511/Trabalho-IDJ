#include "../include/Alien.h"

Alien::Alien(GameObject& associated, int nMinions) : Component(associated) {
    Sprite *alienSprite;
    alienSprite = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(shared_ptr<Component> (alienSprite));
    speed.x = 0;
    speed.y = 0;
    isNewAction = true;
    for(int i = 0; i < nMinions; i++) {
        //minionArray.emplace_back();
    }
    hp = 30;
}

void Alien::Start() {

}

Alien::~Alien() {
    minionArray.clear();
}

void Alien::Update(float dt) {
    Debugger *debugger;
    *debugger = Debugger::GetInstance();
    InputManager *inputManager;
    *inputManager = InputManager::GetInstance();
    Action *newAction;
    Vect2 dif;
    int mousePosX = inputManager->GetMouseX();
    int mousePosY = inputManager->GetMouseY();
    if(debugger->lookUpdateAlien) {
        cout<<"Update de alien inicializando"<<endl;
    }
    if(inputManager->MousePress(LEFT_MOUSE_BUTTON)) {
        newAction = new Action(action->SHOOT, mousePosX, mousePosY);
        taskQueue.push(*newAction);
    } else {
        if(inputManager->MousePress(RIGHT_MOUSE_BUTTON)) {
            newAction = new Action(action->MOVE, mousePosX, mousePosY);
            taskQueue.push(*newAction);
        }
    }
    if(taskQueue.size() >= 1) {
        *action = taskQueue.back();
        if(action->type == action->SHOOT) {
            taskQueue.pop();
        } else {
            if(action->type == action->MOVE) {
                dif.x = action->pos.x - associated.box.x;
                dif.y = action->pos.y - associated.box.y;
                if(isNewAction) {
                    speed.x = dif.x / (30 * dt);
                    speed.y = dif.y / (30 * dt);
                    isNewAction = false;
                }
                if(dif == speed) {
                    associated.box.x = action->pos.x;
                    associated.box.y = action->pos.y;
                    speed.x = 0;
                    speed.y = 0;
                    taskQueue.pop();
                    isNewAction = true;
                }
            }
        }
    }
    if(hp <= 0) {
        associated.RequestedDelete();
    }
}

void Alien::Render() {}

bool Alien::Is(string type) {
    bool result = false;
    if(type == "Alien") {
        result = true;
    }
    return result;
}