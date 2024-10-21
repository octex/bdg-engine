#include "things.h"

void InitThing(Thing *thing)
{
    switch (thing->thingType)
    {
        case PLAYER:
            InitPlayer(thing);
            break;
        case STATIC:
            //InitStaticObj(thing);
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
            //UpdateStaticObj(thing);
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
            //RenderStaticObj(thing);
            break;
        default:
            break;
    }   
}

void InitPlayer(Thing *thing)
{
    thing->position = (Vector2) { 0.0f, 0.0f };
    Player *player = (Player*)thing->thing;
    player->camera = (Camera2D){ 0 };
    player->camera.target = thing->position;
    // player->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
}


void UpdatePlayer(Thing *thing){}


void RenderPlayer(Thing *thing)
{
    Player *player = thing->thing;
    DrawTexture(player->sprite, thing->position.x, thing->position.y, WHITE);
}