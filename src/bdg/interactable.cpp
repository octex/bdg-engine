#include "things.h"

void InitInteractable(Thing *thing)
{
    thing->thing = MemAlloc(sizeof(Interactable));
    Interactable *interactable = (Interactable*)thing->thing;
    interactable->sprite = LoadTexture(assets[thing->strAttrs[ATTR_SPRITE]]);
    // TODO: convertir a script lua
    interactable->scriptSequence = assets[thing->strAttrs[ATTR_SCRIPT]];

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

void UpdateInteractable(Thing *thing)
{

}

void RenderInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    DrawTexture(interactable->sprite, thing->position.x, thing->position.y, WHITE);
}

void UnloadInteractable(Thing *thing)
{
    Interactable *interactable = (Interactable*)thing->thing;
    UnloadTexture(interactable->sprite);
    MemFree(interactable);
}

void Interact(Interactable *interactable)
{
    // TODO: Ejecutar script asociado
}