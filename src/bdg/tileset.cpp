#include "things.h"

void InitTileSet(Thing *thing)
{
    thing->thing = (TileSet*)MemAlloc(sizeof(TileSet));
    TileSet *tileSet = (TileSet*)thing->thing;
    tileSet->sprite = LoadTexture(assets[thing->intAttrs[ATTR_SPRITE]].dir);
    tileSet->tileWidth = thing->intAttrs["tile_width"];
    tileSet->tileHeight = thing->intAttrs["tile_height"];
}

void UnloadTileSet(Thing *thing)
{
    TileSet *tileSet = (TileSet*)thing->thing;
    UnloadTexture(tileSet->sprite);
    MemFree(tileSet);
}