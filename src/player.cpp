#include "things.h"

#include "application.h"
#include <raymath.h>
#include <iostream>

void MovePlayer(Thing *thing, Player *player, Vector2 mousePosition, bool backwards=false)
{
    Vector2 vMovement = Vector2Normalize(mousePosition);
    vMovement = Vector2Scale(vMovement, player->movementSpeed);
    if (backwards)
        vMovement = Vector2Negate(vMovement);
    thing->position = Vector2Add(thing->position, vMovement);
}

void CameraFollow(Vector2 position, Texture2D sprite)
{
    appCamera.target = Vector2{ position.x + sprite.width / 2, position.y + sprite.height / 2 };
}

void InitPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    player->sprite = LoadTexture(assets[thing->assets[0]].dir);
    player->movementSpeed = 5;
}

void UpdatePlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    Vector2 mousePosition = GetMousePosition();
    mousePosition = GetScreenToWorld2D(mousePosition, appCamera);
    mousePosition.x -= thing->position.x;
    mousePosition.y -= thing->position.y;
    player->rotation = atan2(mousePosition.x, mousePosition.y) * -RAD2DEG;

    if (IsKeyDown(KEY_W))
    {
        MovePlayer(thing, player, mousePosition);
    }
    else if (IsKeyDown(KEY_S))
    {
        MovePlayer(thing, player, mousePosition, true);
    }
    CameraFollow(thing->position, player->sprite);
    // std::cout << normalizedMouse.x << " | " << normalizedMouse.y << std::endl;
}

void RenderPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    //DrawTexture(player->sprite, thing->position.x, thing->position.y, WHITE);
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