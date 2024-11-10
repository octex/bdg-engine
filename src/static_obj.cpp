#include "things.h"

#include "application.h"

void InitStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    staticObj->sprite = LoadTexture(assets[thing->assets[0]].dir);
    staticObj->collider = {thing->position.x, thing->position.y, (float)staticObj->sprite.width, (float)staticObj->sprite.height};
}
void UpdateStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    Player *player = (Player*)gamePlayer->thing;
    bool playerCollides = CheckCollisionRecs(staticObj->collider, player->collider);
    if (playerCollides) {
        player->movement = Vector2Add(player->movement, Vector2Negate(player->movement));
        TraceLog(LOG_INFO, "Colisione!");
    }
}
void RenderStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    DrawTexture(staticObj->sprite, thing->position.x, thing->position.y, WHITE);
    DrawRectangleLines(staticObj->collider.x, staticObj->collider.y, staticObj->collider.width, staticObj->collider.height, RED);
}

void UnloadStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    UnloadTexture(staticObj->sprite);
    MemFree(staticObj);
}