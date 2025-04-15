#include "things.h"

#include "application.h"
#include <iostream>

void InitStaticObj(Thing *thing)
{
    thing->thing = MemAlloc(sizeof(StaticObj));
    StaticObj *staticObj = (StaticObj*)thing->thing;

    Texture2D spriteSheet = LoadTexture(assets[thing->strAttrs[ATTR_SPRITE]]);

    staticObj->sprite = spriteSheet;

    // Pivot is centered
    thing->position.x = (thing->position.x - 115) / 2;
    thing->position.y = (thing->position.y - 115) / 2;

    if (thing->hasPhysicalBody) 
    {
        thing->physicalBody->isStatic = true;
        thing->physicalBody->isTrigger = false;
        thing->physicalBody->collider = {thing->position.x, thing->position.y, 230, 230};
    }
}

void UpdateStaticObj(Thing *thing)
{
}

void RenderStaticObj(Thing *thing)
{
    // if (!gamePlayer)
    //     return;
    StaticObj *staticObj = (StaticObj*)thing->thing;
    // DrawTexture(staticObj->sprite, thing->position.x, thing->position.y, WHITE);
    Rectangle rec = {0};
    int baseW = 230;
    rec.height = 230;
    rec.width = 230;
    rec.x = 0;
    rec.y = 0;

    Vector2 vecDistance = Vector2Subtract(gamePlayer->position, thing->position);
    
     /*
        0   :   Sin bordes
        1   :   abajo
        2   :   abajoDerecha
        3   :   derecha
        4   :   arribaDerecha
        5   :   arriba
        6   :   arribaIzquierda
        7   :   izquierda
        8   :   abajoIzquierda
    */
    if (Vector2Distance(gamePlayer->position, thing->position) < 150)
    {
        rec.x = baseW * 0;
    }
    else if(abs(vecDistance.x) <= 115 && vecDistance.y != 0)
    {
        if (vecDistance.y > 0)
        {
            rec.x = baseW * 1;
        }
        else
        {
            rec.x = baseW * 5;
        }
    }
    else if(abs(vecDistance.y) <= 115 && vecDistance.x != 0)
    {
        if (vecDistance.x > 0)
        {
            rec.x = baseW * 3;
        }
        else
        {
            rec.x = baseW * 7;
        }
    }
    else if (vecDistance.x > 0 && vecDistance.y < 0)
    {
        rec.x = baseW * 4;
    }
    else if (vecDistance.x > 0 && vecDistance.y > 0)
    {
        rec.x = baseW * 2;
    }
    else if (vecDistance.x < 0 && vecDistance.y > 0)
    {
        rec.x = baseW * 8;
    }
    else if (vecDistance.x < 0 && vecDistance.y < 0)
    {
        rec.x = baseW * 6;
    }
    DrawTextureRec(staticObj->sprite, rec, thing->position, WHITE);
}

void UnloadStaticObj(Thing *thing)
{
    StaticObj *staticObj = (StaticObj*)thing->thing;
    UnloadTexture(staticObj->sprite);
    MemFree(staticObj);
}