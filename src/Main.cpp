#include "../include/Game.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Prestes a rodar o Jogo..." << endl;
    Game::GetInstance().Run();
    cout << "Removendo Imagens"<<endl;
    Resources::ClearImages();
    cout << "Removendo Musicas"<<endl;
    Resources::ClearMusics();
    cout << "Removendo Sons"<<endl;
    Resources::ClearSounds();
    return 0;
}