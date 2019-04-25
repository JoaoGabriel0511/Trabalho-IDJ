#include "../include/Action.h"

Action::Action(ActionType type, float x, float y) {
    this->type = type;
    pos.x = x;
    pos.y = y;
}

Action::Action() {}