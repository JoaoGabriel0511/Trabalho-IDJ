#include "../include/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, string file) {
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    GameObject *GO;
    GO = new GameObject();
    tileSet = new Sprite(*GO);
    if(tileSet->Open(file)) {
        rows = tileSet->GetHeight() / this->tileHeight;
        columns = tileSet->GetWidth() / this->tileWidth;
        cout<<"rows: "<<rows<<endl;
        cout<<"columns: "<<columns<<endl;
        cout<<"tileset height: "<<tileSet->GetHeight()<<endl;
        cout<<"tileset width: "<<tileSet->GetWidth()<<endl;
    } else {
        cout<<"Falha ao carregar o tileSet: "<< file <<endl;
    }
}

bool TileSet::RenderTile(unsigned index, float x, float y) {
    int tiles = rows * columns;
    int column = 0;
    int row = 0;
    if(index != -1) {
        if(index < tiles) {
            for(int i = 0; i < index; i++) {
                column++;
                if(column == columns) {
                    column = 0;
                    row++;
                }
            }
            column = column * tileWidth;
            row = row * tileHeight;
            tileSet->SetClip(column, row, tileWidth, tileHeight);
            tileSet->Render(x,y,tileWidth,tileWidth);
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

int TileSet::GetWidth() {
    return tileWidth;
}

int TileSet::GetHeight() {
    return tileHeight;
}

int TileSet::GetColums() {
    return columns;
}

int TileSet::GetRows() {
    return rows;
}