#include "things.h"

#include "application.h"
#include <raymath.h>
#include <iostream>

void MovePlayer(Thing *thing, Player *player, Vector2 mousePosition)
{
    bool move = (IsKeyDown(KEY_S) || IsKeyDown(KEY_W));
    bool backwards = IsKeyDown(KEY_S);
    Vector2 normalizedMousePosition = Vector2Normalize(mousePosition);
    Vector2 newVelocity = move ? normalizedMousePosition : Vector2Zero();
    newVelocity = Vector2Scale(newVelocity, player->movementSpeed);
    newVelocity = backwards ? Vector2Negate(newVelocity) : newVelocity;
    thing->physicalBody->velocity = newVelocity;
}

void CameraFollow(Vector2 position, Texture2D sprite)
{
    appCamera.target = Vector2{ position.x + sprite.width / 2, position.y + sprite.height / 2 };
}

void InitPlayer(Thing *thing)
{
    thing->thing = MemAlloc(sizeof(Player));
    Player *player = (Player*)thing->thing;
    player->sprite = LoadTexture(assets[thing->assets[0]].dir);

    thing->position.x = (thing->position.x - player->sprite.width) / 2;
    thing->position.y = (thing->position.y - player->sprite.height) / 2;

    thing->physicalBody->isStatic = false;
    thing->physicalBody->isTrigger = false;
    thing->physicalBody->collider = {thing->position.x, thing->position.y, (float)player->sprite.width, (float)player->sprite.height};
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

    MovePlayer(thing, player, mousePosition);
    CameraFollow(thing->position, player->sprite);
}

void RenderPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    //DrawTexture(player->sprite, thing->position.x, thing->position.y, WHITE);
    // DrawTextureEx(player->sprite, thing.position, player->rotation, 1, WHITE);

    DrawTexturePro(player->sprite, Rectangle{0, 0, (float)player->sprite.width, (float)player->sprite.height},
                       Rectangle{ thing->position.x, thing->position.y, (float)player->sprite.width, (float)player->sprite.height },
                       Vector2{(float)player->sprite.width / 2, (float)player->sprite.height / 2 }, player->rotation, WHITE);
}

void UnloadPlayer(Thing *thing)
{
    Player *player = (Player*)thing->thing;
    UnloadTexture(player->sprite);
    MemFree(player);
}