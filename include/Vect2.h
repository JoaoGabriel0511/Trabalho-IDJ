#ifndef VECT2_H
#define VECT2_H
#include <math.h>
#include <iostream>
using namespace std;
class Vect2{
    public:
        Vect2();
        Vect2(float x, float y);
        ~Vect2();
        Vect2 GetRotated(float nro);
        float x;
        float y;
        float Length();
        float DistanceTo(Vect2 vect);
        Vect2 Normalize();
        Vect2 operator+(Vect2 vet);
        Vect2 operator-(Vect2 vet);
        Vect2 operator*(float nro);
        bool operator==(Vect2 vet);
};
#endif