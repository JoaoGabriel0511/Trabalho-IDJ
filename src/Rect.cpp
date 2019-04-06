#include "../include/Rect.h"
#include <iostream>
using namespace std;

bool Rect::Contains(float mouseX, float mouseY) {
    bool result = true;
    if((mouseX > x + w) || (mouseX < x) || (mouseY > y + h) || (mouseY < y)) {
        result = false;
    }
    return result;
}


Rect::Rect() {
    x =0;
    y=0;
    h=0;
    w=0;
}

Rect::~Rect() {}