#include "things.h"

#include "application.h"
#include <raymath.h>
#include <iostream>

void InitPlayer(Thing *thing)
{
    // thing.position = (Vector2) { 0.0f, 0.0f };
    Player *player = (Player*)thing->thing;
    player->camera = appCamera;
    // player->camera.target = thing.position;
    player->sprite = LoadTexture(assets[thing->assets[0]].dir);
    // player->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
}

void UpdatePlayer(Thing *thing)
{
    // ((Player*)thing.thing)->camera.target = thing.position;
    Player *player = (Player*)thing->thing;
    Vector2 mousePosition = GetMousePosition();
    mousePosition.x -= thing->position.x;
    mousePosition.y -= thing->position.y;
    player->rotation = atan2(mousePosition.x, mousePosition.y) * -RAD2DEG;

    float speed = 5;
    Vector2 vMovement = Vector2Normalize(mousePosition);

    if (IsKeyDown(KEY_W))
    {
        vMovement = Vector2Scale(vMovement, speed);
        thing->position = Vector2Add(thing->position, vMovement);
    }
    else if (IsKeyDown(KEY_S))
    {
        vMovement = Vector2Scale(vMovement, speed);
        vMovement = Vector2Negate(vMovement);
        thing->position = Vector2Add(thing->position, vMovement);
    }
    // std::cout << thing->x << " " << thing->y << std::endl;
}

void RenderPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    // DrawTexture(player->sprite, thing.position.x, thing.position.y, WHITE);
    // DrawTextureEx(player->sprite, thing.position, player->rotation, 1, WHITE);

    DrawTexturePro(player->sprite, Rectangle{0, 0, (float)player->sprite.width, (float)player->sprite.height},
                       Rectangle{ thing->position.x, thing->position.y, (float)player->sprite.width, (float)player->sprite.height },
                       Vector2{(float)player->sprite.height/2, (float)player->sprite.width/2 }, player->rotation - 90, WHITE);
}

void UnloadPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    UnloadTexture(player->sprite);
    MemFree(player);
}