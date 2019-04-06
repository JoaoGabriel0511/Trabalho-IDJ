#include "../include/Component.h"
using namespace std;

Component::Component(GameObject &associated) : associated(associated) {
}

void Component::Update(float dt){}
void Component::Render(){}
bool Component::Is(string type){}
Component::~Component(){}