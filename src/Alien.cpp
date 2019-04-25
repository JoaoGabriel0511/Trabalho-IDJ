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
    InputManager inputManager = InputManager::GetInstance();
    Action *newAction;
    Vect2 dif;
    float hipdif;
    int mousePosX = inputManager.GetMouseX();
    int mousePosY = inputManager.GetMouseY();
    //if(debugger->lookUpdateAlien) {
	//	cout<<"   Inicio do update do alien"<<endl;
	//}
    if(inputManager.MousePress(LEFT_MOUSE_BUTTON)) {
        if(debugger->lookUpdateAlien) {
            cout<<"   Leu o clique esquerdo do mouse"<<endl;
        }
        newAction = new Action(action.SHOOT, mousePosX, mousePosY);
        cout<<"pos x da nova action "<< newAction->pos.x<<endl;
        cout<<"pos y da nova action "<< newAction->pos.y<<endl;
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
            taskQueue.pop();
        } else {
            if(taskQueue.front().type == action.MOVE) {
                if(debugger->lookUpdateAlien) {
		            cout<<"   Leu acao de mover na fila"<<endl;
	            }
                dif.x = taskQueue.front().pos.x - associated.box.x;
                dif.y = taskQueue.front().pos.y - associated.box.y;
                hipdif = sqrt(dif.x * dif.x + dif.y * dif.y);
                if(isNewAction) {
                    speed.x = hipdif / 30 * dt;
                    speed.y = hipdif / 30 * dt;
                    isNewAction = false;
                }
                associated.box.x = associated.box.x + speed.x;
                associated.box.y = associated.box.y + speed.y;
                if(debugger->lookUpdateAlien) {
                    cout<<"     cordenada x de destino "<< taskQueue.front().pos.x<<endl;
                    cout<<"     cordenada x de atual "<<associated.box.x<<endl;
                    cout<<"     distancia x "<<dif.x<<endl;
                    cout<<"     velocidade x  " << speed.x <<endl;
                    cout<<"     cordenada y de destino "<< taskQueue.front().pos.y<<endl;
                    cout<<"     cordenada y de atual "<<associated.box.y<<endl;
                    cout<<"     distancia y "<<dif.y<<endl;
                    cout<<"     velocidade y " << speed.x <<endl;
                    cout<<"     distancia hipotenusa "<<hipdif<<endl;
                }
                if(abs(hipdif) <= 0) {
                    if(debugger->lookUpdateAlien) {
                        cout<<"chegou ao destino"<<endl;
                    }
                    associated.box.x = taskQueue.front().pos.x;
                    associated.box.y = taskQueue.front().pos.y;
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
    //if(debugger->lookUpdateAlien) {
	//	cout<<"   Fim do update do alien"<<endl;
	//}
}

void Alien::Render() {}

bool Alien::Is(string type) {
    bool result = false;
    if(type == "Alien") {
        result = true;
    }
    return result;
}