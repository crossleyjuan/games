#ifndef TILE_H
#define TILE_H

#include "gameengine_global.h"

enum {
    TILE_TYPE_NONE = 0,

    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

class GAMEENGINESHARED_EXPORT  Tile
{
public:
    int     TileID;
    int     TypeID;

public:
    Tile();
};

#endif // TILE_H
