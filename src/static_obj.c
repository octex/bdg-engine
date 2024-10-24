#include "things.h"

void InitStaticObj(Thing *thing)
{
    // StaticObj *staticObj = (StaticObj*)thing->thing;
}
void UpdatStaticObj(Thing *thing)
{

}
void RenderStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    DrawTexture(staticObj->sprite, thing->position.x, thing->position.y, WHITE);
}