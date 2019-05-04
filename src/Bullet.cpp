#include "../include/Bullet.h"

Bullet::Bullet(GameObject& associated, Vect2 direction, float speed, int damage, float maxDistance, string sprite) : Component(associated) {
    Sprite * bulletSprite;
    const float PI = 3.14159265;
    double angleDeg;
    Debugger * debugger;
    *debugger = Debugger::GetInstance();
    if(debugger->lookUpdateBullet) {
        cout<<"Criando um novo bullet na Pos x "<<associated.box.x<<" y "<<associated.box.y<<endl;
        cout<<"Direcao do bullet x "<<direction.x<<" y "<<direction.y<<endl;
    }
    this->start.x = associated.box.x;
    this->start.y = associated.box.y;
    this->speed = speed;
    this->direction = direction;
    distance = maxDistance;
    bulletSprite = new Sprite(associated, sprite);
    associated.AddComponent(shared_ptr<Component> (bulletSprite));
    angleDeg = acos(direction.x) * 180.0 / PI;
    cout<<"angleDeg "<<angleDeg<<endl;
    if(direction.y < 0){
        angleDeg = angleDeg * -1;
    }
    if(debugger->lookUpdateBullet){
        cout<<"angulo "<<angleDeg<<endl;
    }
    associated.angleDeg = angleDeg;
    if(debugger->lookUpdateBullet){
        cout<<"Criou o novo bullet"<<endl;
    }
}

void Bullet::Update(float dt) {
    Debugger * debugger;
    *debugger = Debugger::GetInstance();
    Vect2 goPos;
    goPos.x = associated.box.x;
    goPos.y = associated.box.y;
    if(start.DistanceTo(goPos) > distance) {
        associated.RequestedDelete();
    }
    if(debugger->lookUpdateBullet) {
        cout<<"Inicio do update de bullet"<<endl;
        cout<<"Pos da bullet x "<<associated.box.x<<" y "<<associated.box.y<<endl;
    }
    goPos = goPos + (direction * speed);
    associated.box.x = goPos.x;
    associated.box.y = goPos.y;
    if(debugger->lookUpdateBullet){
        cout<<"Fim do update de bullet"<<endl;
    }
}

void Bullet::Render() {

}

int Bullet::GetDamage() {
    return damage;
}

bool Bullet::Is(string type) {
    bool result = false;
    if(type == "Bullet") {
        result = true;
    }
    return result;
}