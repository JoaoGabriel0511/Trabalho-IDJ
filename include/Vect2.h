#include <math.h>
class Vect2{
    public:
        Vect2();
        Vect2(float x, float y);
        ~Vect2();
        Vect2 GetRotated(float nro);
        float x;
        float y;
        Vect2 operator+(Vect2 vet) {
            Vect2 result;
            result.x = this->x + vet.x;
            result.y = this->y + vet.y;
            return result;
        }
};

