#include "things.h"

#include <iostream>

void InitThing(Thing *thing)
{
    switch (thing->thingType)
    {
        case PLAYER:
            InitPlayer(thing);
            break;
        case STATIC:
            InitStaticObj(thing);
            break;
        case TILESET:
            InitTileSet(thing);
            break;
        case INTERACTABLE:
            InitInteractable(thing);
            break;
        default:
            break;
    }
}


void UpdateThing(Thing *thing)
{
    switch (thing->thingType)
    {
        case PLAYER:
            UpdatePlayer(thing);
            break;
        case STATIC:
            UpdateStaticObj(thing);
            break;
        case INTERACTABLE:
            UpdateInteractable(thing);
            break;
        default:
            break;
    }
}

void RenderThing(Thing *thing)
{
    switch (thing->thingType)
    {
        case PLAYER:
            RenderPlayer(thing);
            break;
        case STATIC:
            RenderStaticObj(thing);
            break;
        case TILEMAP:
            RenderTileMap(thing);
            break;
        case INTERACTABLE:
            RenderInteractable(thing);
            break;
        default:
            break;
    }
}

void UnloadThing(Thing *thing)
{
    switch (thing->thingType)
    {
        case PLAYER:
            UnloadPlayer(thing);
            break;
        case STATIC:
            UnloadStaticObj(thing);
            break;
        case TILEMAP:
            UnloadTileMap(thing);
            break;
        case TILESET:
            UnloadTileSet(thing);
            break;
        case INTERACTABLE:
            UnloadInteractable(thing);
            break;
        default:
            break;
    }
    MemFree(thing);
}

Thing* CreateThing(Vector2 position, ThingType thingType, bool hasPhysicalBody)
{
    Thing* newThing = (Thing*)MemAlloc(sizeof(Thing));
    newThing->position = position;
    newThing->thingType = thingType;
    newThing->hasPhysicalBody = hasPhysicalBody;
    newThing->attrs = {};
    // newThing->parent = parent;
    return newThing;
}

std::string GetThingAttr(Thing *thing, std::string key)
{
    return thing->attrs[key];
}