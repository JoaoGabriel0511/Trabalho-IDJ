#ifndef DEBUGGER
#define DEBUGGER
class Debugger {
public:
    Debugger();
    ~Debugger();
    static Debugger& GetInstance();
    static bool lookUpdateState;
    static bool lookLoopGame;
    static bool lookInputManager;
    static bool lookUpdateAlien;
};
#endif