#include "../include/Minion.h"


Minion::Minion(GameObject& associated, GameObject& alienCenter, float arcOffsetDeg) : Component(associated), alienCenter(alienCenter) {
    float scale = 1 + (rand() % 0 + 5)/10;
    this->alienCenter = alienCenter;
    arc = arcOffsetDeg;
    Sprite * minionSprite;
    minionSprite = new Sprite(associated, "assets/img/minion.png");
    minionSprite->SetScaleX(scale, scale);
    associated.AddComponent(shared_ptr<Component> (minionSprite));
    arcSpeed = 1;
}

bool Minion::Is(string type) {
    bool result = false;
    if(type == "Minion") {
        result = true;
    }
    return result;
}

void Minion::Render() {

}

void Minion::Update(float dt) {
    const float PI = 3.14159265;
    Vect2 vet(200,0);
    vet.x = 200 * cos(arc * PI/180);
    vet.y = 200 * sin(arc * PI/180);
    vet.x += alienCenter.box.x;
    vet.y += alienCenter.box.y;
    associated.box.x = vet.x + alienCenter.box.w /2;
    associated.box.y = vet.y + alienCenter.box.h /2;
    associated.angleDeg = arc;
    arc = arc + arcSpeed;
}

void Minion::Shoot(Vect2 direction) {
    GameObject * bulletGO;
    Game * instance;
    instance = &Game::GetInstance();
    Bullet * bullet;
    bulletGO = new GameObject();
    bulletGO->box.x = associated.box.x;
    bulletGO->box.y = associated.box.y;
    bullet = new Bullet(*bulletGO, direction, 10, 10, 500, "assets/img/minionbullet1.png");
    bulletGO->AddComponent(shared_ptr<Component> (bullet));
    instance->GetState().AddObject(bulletGO);
}
