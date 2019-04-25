#include "../include/Debugger.h"
bool Debugger::lookLoopGame;
bool Debugger::lookInputManager;
bool Debugger::lookUpdateState;
bool Debugger::lookUpdateAlien;
Debugger::Debugger() {
    lookLoopGame = false;
    lookUpdateState = false;
    lookInputManager = false;
    lookUpdateAlien = true;
}

Debugger::~Debugger(){}

Debugger& Debugger::GetInstance() {
    static  Debugger debugger;
    return debugger;
}