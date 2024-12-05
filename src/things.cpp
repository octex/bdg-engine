#include "things.h"

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
}

bool CheckCollisionRecsX(Rectangle rec1, Rectangle rec2)
{
    bool collision = false;

    if (rec1.x < (rec2.x + rec2.width) && (rec1.x + rec1.width) > rec2.x)
        collision = true;

    return collision;
}

bool CheckCollisionRecsY(Rectangle rec1, Rectangle rec2)
{
    bool collision = false;

    if (rec1.y < (rec2.y + rec2.height) && (rec1.y + rec1.height) > rec2.y)
        collision = true;

    return collision;
}