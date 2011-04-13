#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <vector>

#include "tile.h"
#include "surface.h"
#include "gameengine_global.h"

class GAMEENGINESHARED_EXPORT Map {
    public:
        SDL_Surface* Surf_Tileset;

    private:
        std::vector<Tile> TileList;

    public:
        Map();

    public:
        bool OnLoad(char* File);

        void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
public:
    Tile*  GetTile(int X, int Y);
};
#endif // MAP_H
