#include "things.h"

void InitThing(Thing thing)
{
    switch (thing.thingType)
    {
        case PLAYER:
            InitPlayer(thing);
            break;
        case STATIC:
            InitStaticObj(thing);
            break;
        default:
            break;
    }
}


void UpdateThing(Thing thing)
{
    switch (thing.thingType)
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

void RenderThing(Thing thing)
{
    switch (thing.thingType)
    {
        case PLAYER:
            RenderPlayer(thing);
            break;
        case STATIC:
            RenderStaticObj(thing);
            break;
        default:
            break;
    }   
}