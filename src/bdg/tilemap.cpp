#include "things.h"

void InitTileMap(Thing *thing)
{
    
}

void UpdateTileMap(Thing *thing)
{

}

void RenderTileMap(Thing *thing)
{
    TileMap *tileMap = (TileMap*)thing->thing;
    for (Tile tile: tileMap->tiles)
    {
        Texture2D tileTexture = tile.tileSet->sprite;
        
        Vector2 normalizedTilePosition = thing->position;
        normalizedTilePosition.x += tileMap->xCell * tile.tilePosition.x;
        normalizedTilePosition.y += tileMap->yCell * tile.tilePosition.y;
        
        Rectangle tileRect = {0};
        tileRect.height = tileMap->yCell;
        tileRect.width = tileMap->xCell;
        tileRect.x = tileMap->xCell * tile.index - tileMap->xCell;
        DrawTextureRec(tileTexture, tileRect, normalizedTilePosition, WHITE);
    }
}

void UnloadTileMap(Thing *thing)
{
    MemFree(thing->thing);
}