#include "../include/Alien.h"
#define PI 3.14159265
Alien::Alien(GameObject& associated, int nMinions) : Component(associated) {
    Sprite *alienSprite;
    alienSprite = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(shared_ptr<Component> (alienSprite));
    isNewAction = true;
    hp = 30;
    rotationSpeed = 0.5;
}

void Alien::Start() {
    cout<<"start do alien"<<endl;
    for(int i = 0; i < 3; i++){
        cout<<"add minion "<<i<<endl;
        AddMinion(i);
        cout<<"adicionou"<<endl;
    }
}

void Alien::AddMinion(int arc) {
    GameObject * newGO;
    Game *instance;
    instance = &Game::GetInstance();
    Minion * minion;
    newGO = new GameObject();
    minion = new Minion(*newGO, associated, arc * 120);
    newGO->AddComponent(shared_ptr<Component> (minion));
    State * state;
    state = &instance->GetState();
    minionArray.emplace_back(state->AddObject(newGO));
}

Alien::~Alien() {
    minionArray.clear();
}

void Alien::Update(float dt) {
    Debugger *debugger;
    *debugger = Debugger::GetInstance();
    InputManager inputManager = InputManager::GetInstance();
    Action *newAction;
    int mousePosX = inputManager.GetMouseX();
    int mousePosY = inputManager.GetMouseY();
    //if(debugger->lookUpdateAlien) {
	//	cout<<"   Inicio do update do alien"<<endl;
	//}
    associated.angleDeg -= rotationSpeed;
    if(inputManager.MousePress(LEFT_MOUSE_BUTTON)) {
        if(debugger->lookUpdateAlien) {
            cout<<"   Leu o clique esquerdo do mouse"<<endl;
        }
        newAction = new Action(action.SHOOT, mousePosX, mousePosY);
        taskQueue.push(*newAction);
    }
    if(inputManager.MousePress(RIGHT_MOUSE_BUTTON)) {
        if(debugger->lookUpdateAlien) {
		    cout<<"   Leu o clique direito do mouse"<<endl;
	    }
        newAction = new Action(action.MOVE, mousePosX, mousePosY);
        taskQueue.push(*newAction);
    }
    if(taskQueue.size() != 0) {
        if(debugger->lookUpdateAlien) {
            cout<<"proxima action eh "<< taskQueue.front().type<<endl;
        }
        if(taskQueue.front().type == action.SHOOT) {
            ShootBullet(dt);
        } else {
            if(taskQueue.front().type == action.MOVE) {
                MoveAlien(dt);
            }
        }
    }
    if(hp <= 0) {
        associated.RequestedDelete();
    }
    //if(debugger->lookUpdateAlien) {
	//	cout<<"   Fim do update do alien"<<endl;
	//}
}

void Alien::ShootBullet(float dt) {
    GameObject * closestMinion;
    GameObject * currentMinion;
    bool first = true;
    Vect2 currentMinionPos;
    Vect2 closestMinionPos;
    Vect2 target = taskQueue.front().pos - Camera::pos;
    for(int i = 0; i < minionArray.size(); i++){
        currentMinion = minionArray[i].lock().get();
        currentMinionPos.x = currentMinion->box.x;
        currentMinionPos.y = currentMinion->box.y;
        if(first) {
            first = false;
            closestMinion = currentMinion;
            closestMinionPos.x = closestMinion->box.x;
            closestMinionPos.y = closestMinion->box.y;
        } else {
            if(currentMinionPos.DistanceTo(target) <  closestMinionPos.DistanceTo(target)){
                closestMinion = currentMinion;
                closestMinionPos.x = closestMinion->box.x;
                closestMinionPos.y = closestMinion->box.y;
           }
        }
    }
    start.x = closestMinion->box.x;
    start.y = closestMinion->box.y;
    end = taskQueue.front().pos - Camera::pos;
    direction = end - start;
    direction = direction.Normalize();
    ((Minion*) closestMinion->GetComponent("Minion").get())->Shoot(direction);
    taskQueue.pop();
}

void Alien::MoveAlien(float dt) {
    Debugger * debugger;
    *debugger = Debugger::GetInstance();
    if(debugger->lookUpdateAlien) {
        cout<<"   Leu acao de mover na fila"<<endl;
    }
    if(isNewAction) {
        if(debugger->lookUpdateAlien) {
            cout<<"     Eh nova acao"<<endl;
        }
        hipspeed = 300 * dt;
        start.x = associated.box.x;
        start.y = associated.box.y;
        end = taskQueue.front().pos - Camera::pos;
        goPos = start;
        distance = start.DistanceTo(end);
        direction = end - start;
        direction = direction.Normalize();
        cout<<"Direction x "<<direction.x<<" y "<<direction.y<<endl;
        isNewAction = false;
    }
    goPos = goPos + (direction * hipspeed);
    associated.box.x = goPos.x;
    associated.box.y = goPos.y;
    if(debugger->lookUpdateAlien) {
        cout<<"  Cordenadas de inicio (x: "<< start.x <<", y: "<<start.y<<")"<<endl;
        cout<<"  Cordenadas de destino (x: "<< end.x <<", y: "<<end.y<<")"<<endl;
        cout<<"  Cordenadas atuais (x: "<< associated.box.x <<", y: "<<associated.box.y<<")"<<endl;
        cout<<"  Distancia "<< distance<<endl;
    }
    if(start.DistanceTo(goPos) >= distance) {
        if(debugger->lookUpdateAlien) {
            cout<<"chegou ao destino"<<endl;
        }
        associated.box.x = end.x;
        associated.box.y = end.y;
        hipspeed = 0;
        taskQueue.pop();
        isNewAction = true;
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