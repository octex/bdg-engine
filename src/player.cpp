#include "things.h"

void InitPlayer(Thing thing)
{
    thing.position = (Vector2) { 0.0f, 0.0f };
    Player *player = (Player*)thing.thing;
    player->camera = (Camera2D){ 0 };
    player->camera.target = thing.position;
    // player->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
}

void UpdatePlayer(Thing thing){}

void RenderPlayer(Thing thing)
{
    Player *player = (Player*)thing.thing;
    DrawTexture(player->sprite, thing.position.x, thing.position.y, WHITE);
}

void UnloadPlayer(Thing thing)
{
    
}