#include "../include/Debugger.h"
bool Debugger::lookLoopGame;
bool Debugger::lookInputManager;
bool Debugger::lookUpdateState;
bool Debugger::lookUpdateAlien;
bool Debugger::lookUpdateBullet;
Debugger::Debugger() {
    lookLoopGame = false;
    lookUpdateState = false;
    lookInputManager = false;
    lookUpdateAlien = false;
    lookUpdateBullet = false;
}

Debugger::~Debugger(){}

Debugger& Debugger::GetInstance() {
    static  Debugger debugger;
    return debugger;
}