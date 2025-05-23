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
    newThing->intAttrs = {};
    newThing->floatAttrs = {};
    newThing->strAttrs = {};
    // newThing->parent = parent;
    return newThing;
}

void SetThingAttr(Thing* thing, std::string key, int value)
{
    thing->intAttrs[key] = value;
}

void SetThingAttr(Thing* thing, std::string key, float value)
{
    thing->floatAttrs[key] = value;
}

void SetThingAttr(Thing* thing, std::string key, std::string value)
{
    thing->strAttrs[key] = value;
}