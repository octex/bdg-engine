#include "things.h"
#include "bdg_lua.h"
#include "application.h"

#include <iostream>

void InitInteractable(Thing *thing)
{
    thing->thing = MemAlloc(sizeof(Interactable));
    Interactable *interactable = (Interactable*)thing->thing;
    // interactable->sprite = LoadTexture(assets[GetThingAttr(thing, ATTR_SPRITE)]);
    GetAsset(GetThingAttr(thing, ATTR_SPRITE), ASSET_TEXTURE, &interactable->sprite);
    interactable->hover = false;
    interactable->tooltip = GetThingAttr(thing, ATTR_TOOLTIP);

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
    std::string filePath;
    GetAsset(GetThingAttr(thing, ATTR_SCRIPT), ASSET_SCRIPT, &filePath);
    sol::state state = ReadLuaFile(filePath);
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
    Color spriteColor = interactable->hover ? GREEN : WHITE;
    Color hoverColor = GREEN;
    DrawTexture(interactable->sprite, thing->position.x, thing->position.y, spriteColor);
    if (interactable->hover)
    {
        Player* player = (Player*)gamePlayer->thing;
        DrawText(interactable->tooltip.c_str(), player->rayPoint.x, player->rayPoint.y, 12, WHITE);
    }
}

void UnloadInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    UnloadTexture(interactable->sprite);
    MemFree(interactable);
}