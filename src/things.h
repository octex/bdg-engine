#ifndef THINGS_H
#define THINGS_H

#include <vector>
#include "raylib.h"
#include "assets.h"

//  ---------------------------------
//  General definitions for Thing
//  ---------------------------------

typedef enum ThingType {
    PLAYER,
    ENTITY,
    STATIC,
    ITEM,
    INTERACTABLE,
    PROP,
    TILEMAP,
    TILESET,
} ThingType;

typedef struct Thing
{
    unsigned int thingId;
    Vector2 position;
    float x, y;
    ThingType thingType;
    std::vector<int> assets;
    void *thing;
} Thing;

void InitThing(Thing *thing);
void UpdateThing(Thing *thing);
void RenderThing(Thing *thing);
void UnloadThing(Thing *thing);


//  ---------------------------------
//  Item definition
//  ---------------------------------

typedef struct Item {
    Texture texture;
    Rectangle collider;
} Item;

void InitItem(Thing *thing);
void UpdateItem(Thing *thing);
void RenderItem(Thing *thing);


//  ---------------------------------
//  Player definition
//  ---------------------------------

typedef struct Player {
    Camera2D camera;
    Texture2D sprite;
    float rotation;
} Player;

void InitPlayer(Thing *thing);
void UpdatePlayer(Thing *thing);
void RenderPlayer(Thing *thing);
void UnloadPlayer(Thing *thing);

//  ---------------------------------
//  Static obj definition
//  ---------------------------------

typedef struct StaticObj
{
    Texture2D sprite;
    Rectangle collider;
} StaticObj;

void InitStaticObj(Thing *thing);
void UpdateStaticObj(Thing *thing);
void RenderStaticObj(Thing *thing);
void UnloadStaticObj(Thing *thing);

//  ---------------------------------
//  TileSet definition
//  ---------------------------------

typedef struct TileSet {
    Texture2D sprite;
    int tileWidth, tileHeight;
} TileSet;

typedef struct Tile {
    Vector2 tilePosition;   // Relative to screen position
    int index;              // Starts at 1
    TileSet *tileSet;
} Tile;

void InitTileSet(Thing *thing);
void UnloadTileSet(Thing *thing);

//  ---------------------------------
//  TileMap definition
//  ---------------------------------

typedef struct TileMap {
    std::vector<Tile> tiles;
    int xCell, yCell;
} TileMap;

void InitTileMap(Thing *thing);
void UpdateTileMap(Thing *thing);
void RenderTileMap(Thing *thing);
void UnloadTileMap(Thing *thing);

#endif