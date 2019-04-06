#include "../include/Game.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Antes do Game.run" << endl;
    Game::GetInstance().Run();
    return 0;
}