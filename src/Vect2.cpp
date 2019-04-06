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
    x = x * cos(angle) - y * sin(angle);
    y = y * cos(angle) + x * sin(angle);
}


