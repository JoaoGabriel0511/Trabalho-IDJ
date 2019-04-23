#ifndef ACTION_H
#define ACTION_H
#include "Vect2.h"
    class Action {
    public:
        enum ActionType { MOVE, SHOOT};
        ActionType type;
        Vect2 pos;
        Action(ActionType type, float x, float y);
    };

#endif