#include "things.h"

void InitStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    staticObj->sprite = LoadTexture(assets[thing->assets[0]].dir);
    staticObj->collider = {thing->position.x, thing->position.y, (float)staticObj->sprite.width, (float)staticObj->sprite.height};
}
void UpdateStaticObj(Thing *thing)
{

}
void RenderStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    DrawTexture(staticObj->sprite, thing->position.x, thing->position.y, WHITE);
}

void UnloadStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    UnloadTexture(staticObj->sprite);
    MemFree(staticObj);
}