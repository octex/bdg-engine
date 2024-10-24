#include "scenes.h"

void InitThings(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        InitThing(thing);
    }
}

void UpdateThings(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        UpdateThing(thing);
    }
}

void RenderThings(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        RenderThing(thing);
    }
}