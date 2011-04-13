#ifndef AREA_H
#define AREA_H

#include "Map.h"

class GAMEENGINESHARED_EXPORT Area
{
public:
    static Area            AreaControl;

public:
    std::vector<Map>       MapList;

private:
    int                     AreaSize;

    SDL_Surface*            Surf_Tileset;

public:
    Area();
    bool OnLoad(char* File);
    void OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
    void OnCleanup();

public:
    Map*   GetMap(int X, int Y);
    Tile*  GetTile(int X, int Y);
};

#endif // AREA_H
