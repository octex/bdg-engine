#ifndef THINGS_H
#define THINGS_H

#include <vector>
#include <string>
#include "raylib.h"
#include "assets.h"

#define ATTR_SPRITE "attr_sprite"
#define ATTR_PHYSICS_VELOCITY "attr_velocity"

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
    ThingType thingType;
    bool hasPhysicalBody;
    void *thing;
    struct PhysicThing *physicalBody;
    std::map<std::string, int> intAttrs;
    std::map<std::string, float> floatAttrs;
} Thing;

void InitThing(Thing *thing);
void UpdateThing(Thing *thing);
void RenderThing(Thing *thing);
void UnloadThing(Thing *thing);


Thing* CreateThing(Vector2 position, ThingType thingType, bool hasPhysicalBody);
void SetThingAttr(Thing* thing, std::string key, int value);
void SetThingAttr(Thing* thing, std::string key, float value);


// -----------------------------------------
//  Animation structures
// -----------------------------------------

typedef enum ThingAnimationState
{
    READY,
    PLAYING,
    PAUSED
} ThingAnimationState;

typedef struct ThingAnimation
{
    ThingAnimationState state;
    int frameRate, frames, frames_per_y_axis;
    int frame = 0;
    Texture2D sprites;
} ThingAnimation;

typedef struct ThingAnimator
{
    ThingAnimation *currentAnimation;
    std::map <int, ThingAnimation*> animations;
} ThingAnimator;

void InitAnimator(ThingAnimator*);
void SetAndPlayAnimation(ThingAnimator*, int);

void UpdateStatus(ThingAnimation*, ThingAnimationState);
void PlayAnimation(ThingAnimation*);
void PauseAnimation(ThingAnimation*);
void StopAnimation(ThingAnimation*);
void RenderAnimation(ThingAnimation*);

//  ---------------------------------------------------
//  Physical thing definition
//  If is static, velocity will always be zero.
//  If is trigger, collision handling will be ignored.
//  ---------------------------------------------------

typedef struct PhysicThing
{
    bool isStatic, isTrigger;
    Thing *thing;
    Rectangle collider;
    Vector2 velocity;
} PhysicThing;

typedef struct CollisionPair
{
    Thing *a, *b;
} CollisionPair;

//  ---------------------------------
//  Item definition
//  ---------------------------------

typedef struct Item {
    Texture texture;
} Item;

void InitItem(Thing *thing);
void UpdateItem(Thing *thing);
void RenderItem(Thing *thing);


//  ---------------------------------
//  Player definition
//  ---------------------------------

typedef enum PlayerState {
    IDLE,
    WALKING
} PlayerState;

typedef struct Player {
    ThingAnimator *animator;
    Texture2D sprite;
    float rotation, movementSpeed;
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