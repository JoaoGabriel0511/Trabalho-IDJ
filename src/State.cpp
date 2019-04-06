#include "../include/State.h"
#include <iostream>
#include "unistd.h"
#define PI 3.149
using namespace std;
State::State() {
    quitRequested = false;
	cout << "Antes do LoadAssets de State" << endl;
    LoadAssets();
	cout << "Depois do LoadAssets de State" << endl;
    ((Music*) bg->GetComponent("Music").get())->Play(-1);
	cout << "Depois de play music" << endl;
}

void State::Update(float dt) {
    Input();
    for(int i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Update(0);
    }
	for(int j = 0; j < objectArray.size(); j++) {
		cout<<"isDEad state Update "<<j<<" "<<objectArray[j]->IsDead()<<endl;
		if(objectArray[j]->IsDead() == true) {
			Sound* sound;
			sound = ((Sound*) objectArray[j]->GetComponent("Sound").get());
			sound->Play(0.5);
			sleep(1);
			if(Mix_Playing(sound->chanel)){
				objectArray.erase(objectArray.begin() + j);
			}
			cout<<"depois do erase"<<endl;
        }
	}
}

void State::Render() {
    for(int i = 0; i < objectArray.size(); i++) {
        objectArray[i]->Render();
    }
}

bool State::QuitRequested() {
    return quitRequested;
}

void State::LoadAssets(){
    Sprite *sprite;
    Music *music;
    bg = new GameObject();
    sprite = new Sprite(*bg, "assets/img/ocean.jpg");
	bg->box.h = sprite->GetHeight();
	bg->box.w = sprite->GetWidth();
    music = new Music(*bg, "assets/audio/stageState.ogg");
    bg->AddComponent(shared_ptr<Component> (sprite));
    bg->AddComponent(shared_ptr<Component> (music));
	cout<<"object array size inicio "<<objectArray.size()<<endl;
	objectArray.emplace_back(bg);
	cout<<"object array size inicio oo "<<objectArray.size()<<endl;
}

State::~State() {
    objectArray.clear();
}

void State::AddObject(int mouseX, int mouseY) {
    GameObject *newGO;
    Sound *newSound;
    Sprite *newSP;
    Face *newFace;
    newGO = new GameObject();
    newSP = new Sprite(*newGO, "assets/img/penguinface.png");
    newGO->box.x = mouseX;
    newGO->box.y = mouseY;
	newGO->box.h = newSP->GetHeight();
	newGO->box.w = newSP->GetWidth();
	cout << "Penguin esta em X:" << newGO->box.x << "-Y:" << newGO->box.y << endl;
	cout << "Tamanho do penguin W:" << newGO->box.w << "-H:" << newGO->box.h << endl;
    newSound = new Sound(*newGO, "assets/audio/boom.wav");
    newFace = new Face(*newGO);
    newGO->AddComponent(shared_ptr<Component> (newSP));
    newGO->AddComponent(shared_ptr<Component> (newSound));
    newGO->AddComponent(shared_ptr<Component> (newFace));
	cout<<"object array antes de adicionar "<<objectArray.size()<<endl;
    objectArray.emplace_back(newGO);
	cout<<"object array depois de adicionar "<<objectArray.size()<<endl;

}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.
				bool clickou = go->box.Contains((float)mouseX, (float)mouseY);
				if(clickou) {
					cout << "CLICKOU NO PINGUIN" << endl;
					Face* face = (Face*)go->GetComponent( "Face" ).get();
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(30);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vect2 objPos = Vect2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vect2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}
