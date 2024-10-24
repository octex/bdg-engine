#ifndef THINGS_H
#define THINGS_H

#include "raylib.h"

//  ---------------------------------
//  General definitions for Thing
//  ---------------------------------

typedef enum ThingType {
    PLAYER,
    ENTITY,
    STATIC,
    ITEM,
    INTERACTABLE,
    PROP
} ThingType;

typedef struct Thing
{
    unsigned int thingId;
    Vector2 position;
    ThingType thingType;
    void *thing;
} Thing;

void InitThing(Thing *thing);
void UpdateThing(Thing *thing);
void RenderThing(Thing *thing);


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
} Player;

void InitPlayer(Thing *thing);
void UpdatePlayer(Thing *thing);
void RenderPlayer(Thing *thing);

//  ---------------------------------
//  Static obj definition
//  ---------------------------------

typedef struct StaticObj
{
    Texture2D sprite;
    Rectangle collider;
} StaticObj;

void InitStaticObj(Thing *thing);
void UpdatStaticObj(Thing *thing);
void RenderStaticObj(Thing *thing);


#endif