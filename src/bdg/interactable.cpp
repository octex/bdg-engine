#include "things.h"
#include "bdg_lua.h"
#include "application.h"

#include <iostream>

void InitInteractable(Thing *thing)
{
    thing->thing = MemAlloc(sizeof(Interactable));
    Interactable *interactable = (Interactable*)thing->thing;
    interactable->sprite = LoadTexture(assets[thing->strAttrs[ATTR_SPRITE]]);
    interactable->hover = false;

    // Pivot is centered
    thing->position.x = (thing->position.x - interactable->sprite.width) / 2;
    thing->position.y = (thing->position.y - interactable->sprite.height) / 2;

    if (thing->hasPhysicalBody)
    {
        thing->physicalBody->isStatic = true;
        thing->physicalBody->isTrigger = false;
        thing->physicalBody->collider = {thing->position.x, thing->position.y, (float)interactable->sprite.width, (float)interactable->sprite.height};
    }
}

void Interact(Thing *thing)
{
    sol::state state = ReadLuaFile(assets[thing->strAttrs[ATTR_SCRIPT]]);
    state.script("interact()");
}

void UpdateInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    Player* player = (Player*)gamePlayer->thing;
    interactable->hover = CheckCollisionPointRec(player->rayPoint, thing->physicalBody->collider);
    if (interactable->hover)
    {
        player->interactable = thing;
    }
    else
    {
        if (player->interactable == thing)
        {
            player->interactable = NULL;
        }
    }
}

void RenderInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    Color spriteColor = WHITE;
    Color hoverColor = GREEN;
    if (interactable->hover)
    {
        spriteColor = hoverColor;
    } else { spriteColor = WHITE; }
    DrawTexture(interactable->sprite, thing->position.x, thing->position.y, spriteColor);
}

void UnloadInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    UnloadTexture(interactable->sprite);
    MemFree(interactable);
}