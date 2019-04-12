#include "../include/Vect2.h"

Vect2::Vect2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vect2::Vect2() {
    this->x = 0;
    this->y = 0;
}

Vect2::~Vect2() {}

Vect2 Vect2::GetRotated(float angle){
    int value_x = this->x;
    int value_y = this->y;
    x = value_x * cos(angle) - value_y * sin(angle);
    y = value_y * cos(angle) + value_x * sin(angle);
    return Vect2(x,y);
}


