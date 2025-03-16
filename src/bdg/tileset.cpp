#include "things.h"

void InitTileSet(Thing *thing)
{
    TileSet *tileSet = (TileSet*)thing->thing;
    tileSet->sprite = LoadTexture(assets[thing->intAttrs[ATTR_SPRITE]].dir);
}

void UnloadTileSet(Thing *thing)
{
    TileSet *tileSet = (TileSet*)thing->thing;
    UnloadTexture(tileSet->sprite);
    MemFree(tileSet);
}