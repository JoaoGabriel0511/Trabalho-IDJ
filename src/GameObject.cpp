#include "../include/GameObject.h"
using namespace std;

GameObject::GameObject(){
    isDead = false;
    started = false;
    angleDeg = 0;
}

GameObject::~GameObject(){
    int components_size = components.size();
    for(int i = components_size-1; i >= 0; i--) {
        if(components[i]->Is("Sprite")){
            cout<<"Deletando Sprite"<<endl;
        }
        if(components[i]->Is("Sound")){
            cout<<"Deletando Sound"<<endl;
        }
        if(components[i]->Is("Face")){
            cout<<"Deletando Face"<<endl;
        }
        components.erase(components.begin() + i);
        cout<<"component deletado"<<endl;
    }
    cout<<"Terminou com seucesso de deletar components"<<endl;
    //components.clear();
    cout<<"clear nos components"<<endl;
}

void GameObject::Update(float dt) {
    int components_size = components.size();
    for(int i = 0; i < components_size; i++) {
        components[i]->Update(dt);
    }
}

void GameObject::Start() {
    for(int i = components.size()-1; i >= 0; i--) {
        components[i]->Start();
    }
    started = true;
}

void GameObject::Render() {
    int components_size = components.size();
    for(int i = 0; i < components_size; i++) {
        components[i]->Render();
    }
}

bool GameObject::IsDead() {
    return isDead;
}

void GameObject::RequestedDelete() {
    this->isDead = true;
}

void GameObject::AddComponent(shared_ptr<Component> cpt){
    components.emplace_back(cpt);
    if(started == true) {
        cpt->Start();
    }
}

void GameObject::RemoveComponent(shared_ptr<Component> cpt) {
    int components_size = components.size();
    for(int i = 0; i <= components_size; i++) {
        if(components[i] == cpt){
            components.erase(components.begin() + i);
        }
    }
}

shared_ptr<Component> GameObject::GetComponent(string type){
    int components_size = components.size();
    shared_ptr<Component> component = NULL;
    for(int i = 0; i < components_size; i++) {
        if(components[i]->Is(type)){
            component = components[i];
        }
    }
    return component;
}