#include "../include/TileMap.h"

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated) {
    this->tileSet = tileSet;
    Load(file);
}

void TileMap::Load(string file){
    int row = 0;
    ifstream myFile;
    string line;
    myFile.open("assets/map/tileMap.txt");
    cout<<"Lendo o tileMap: "<<endl;
    while(getline(myFile,line)){
        if(row == 0){
            mapWidth = stoi(line.substr(0,2));
            mapHeight = stoi(line.substr(3,5));
            mapDepth = stoi(line.substr(6,7));
            cout<<stoi(line.substr(0,2))<<" "<<stoi(line.substr(3,5))<<" "<<stoi(line.substr(6,7))<<endl;
        }
        if(row > 1 && row != 27) {
            for(int i = 0; i < 75; i = i + 3) {
                cout<< stoi(line.substr(i,i+2))<< " ";
                tileMatrix.push_back(stoi(line.substr(i,i+2))-1);
            }
            cout<<endl;
        }
        row++;
    }
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z = 0){
    int aux;
    int aux2;
    int pos;
    aux = mapHeight * mapWidth * mapDepth;
    aux2 = mapWidth * y - 1;
    pos = x + aux + aux2;
    return tileMatrix[pos];
}

void TileMap::Render() {
    //cout<<"Renderizando mapa do jogo..."<<endl;
    for(int i = 0; i < mapDepth; i++){
    //  cout<<"Renderizando layer "<< i << " do jogo"<<endl;
        RenderLayer(i,Camera::pos.x,Camera::pos.y);
    //    cout<<"Layer "<< i << " do jogo renderizado"<<endl;
    }
    //cout<<"Mapa renderizado"<<endl;
}
void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int aux = mapHeight * mapWidth * layer;
    int aux2 = 0;
    int aux3 = 0;
    float posx = 0;
    float posy = 0;
    for (int i = aux; i < aux + mapHeight * mapWidth; i++) {
        aux2 = i - aux;
        if( aux2 >= mapWidth * (aux3+ 1)) {
            aux3++;
            posy = posy + tileSet->GetHeight();
        }
        aux2 = aux2 - mapWidth * aux3;
        posx = aux2 * tileSet->GetWidth();
        if(tileSet->RenderTile(tileMatrix[i], posx + cameraX * (1+layer), posy + cameraY *(1+layer))){
            //cout<<"carregou tile pos("<<posx<<","<<posy<<") index: "<<tileMatrix[i]<<endl;
        } else {
            //cout<<"falha ao carregar tile pos("<<posx<<","<<posy<<") index: "<<tileMatrix[i]<<endl;
        }
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

bool TileMap::Is(string type) {
    if(type == "TileMap") {
        return true;
    } else {
        return false;
    }
}

void TileMap::Update(float dt) {
}

TileMap::~TileMap(){
}