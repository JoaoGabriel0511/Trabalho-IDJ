#ifndef TILE_MAP_H
#define TILE_MAP_H
#include "TileSet.h"
#include <fstream>
using namespace std;
class TileSet;
class TileMap : public Component {
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
    public:
        TileMap(GameObject& associated, string file, TileSet* tileSet);
        void Load(string file);
        void SetTileSet(TileSet* tileSet);
        int& At(int x, int y, int z);
        void Render();
        void RenderLayer(int layer, int cameraX, int cameraY);
        int GetWidth();
        int GetHeight();
        int GetDepth();
        bool Is(string file);
        void Update(float dt);
        ~TileMap();
};
#endif