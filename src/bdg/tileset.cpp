#include "things.h"

void InitTileSet(Thing *thing)
{
    thing->thing = (TileSet*)MemAlloc(sizeof(TileSet));
    TileSet *tileSet = (TileSet*)thing->thing;
    tileSet->sprite = LoadTexture(assets[thing->strAttrs[ATTR_SPRITE]]);
    tileSet->tileWidth = thing->intAttrs[ATTR_TILE_WIDTH];
    tileSet->tileHeight = thing->intAttrs[ATTR_TILE_HEIGHT];
}

void UnloadTileSet(Thing *thing)
{
    TileSet *tileSet = (TileSet*)thing->thing;
    UnloadTexture(tileSet->sprite);
    MemFree(tileSet);
}