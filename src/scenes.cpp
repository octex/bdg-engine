#include "scenes.h"

#include <iostream>

void InitScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        InitThing(thing);
    }

    for (PhysicThing *pThing : scene->physicalThings)
    {
        if (!pThing->isStatic)
        {
            scene->dynamicThings.push_back(pThing);
        } else {
            scene->staticThings.push_back(pThing);
        }
    }
}

void UpdateScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        UpdateThing(thing);
    }
    UpdateXAxis(scene);
    UpdateYAxis(scene);
}

void RenderScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        RenderThing(thing);
    }
    if (RENDER_COLLIDERS)
    {
        for (PhysicThing *pThing : scene->physicalThings)
        {
            DrawRectangleLines(pThing->collider.x,
                                pThing->collider.y,
                                pThing->collider.width,
                                pThing->collider.height,
                                RED);
        }
    }
}

void UnloadScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        UnloadThing(thing);
    }
}

void UpdateXAxis(Scene *scene)
{
    for (PhysicThing *thing : scene->dynamicThings)
    {
        thing->collider.x = thing->thing->position.x - thing->collider.width / 2;
        thing->thing->position.x += thing->velocity.x;
    }

    for (PhysicThing *dThing : scene->dynamicThings)
    {
        for (PhysicThing *sThing : scene->staticThings)
        {
            bool collides = CheckCollisionRecs(dThing->collider, sThing->collider);
            if (collides)
            {
                /*
                    08/01/2025 - 00:45
                    Dejo estas notas porque no me da la cabeza ya (en realidad me levanto temprano el cerebro me sobra la verdad en este momento)
                        - No funciona con colisiones superpuestas
                        - La misma logica aplicada en el eje Y rompe todo
                        - No esta separando los objetos, solo lo "frena"
                    Hay que hacer uso de los pares de colision y ver si realmente aplica
                    en base a cada eje
                */
                float distance = 0;
                if (dThing->collider.x < sThing->collider.x)
                {
                    distance = (dThing->collider.x + (dThing->collider.width)) - sThing->collider.x;
                }
                else if (dThing->collider.x > sThing->collider.x)
                {
                    distance = dThing->collider.x - (sThing->collider.x + (sThing->collider.width));
                }
                distance = -distance;                   // Todavia no se por que, pero es necesario.
                dThing->thing->position.x += distance;
            }
        }
    }
}

void UpdateYAxis(Scene *scene)
{
    for (PhysicThing *thing : scene->dynamicThings)
    {
        thing->collider.y = thing->thing->position.y - thing->collider.height / 2;
        thing->thing->position.y += thing->velocity.y;
    }

    // for (PhysicThing *dThing : scene->dynamicThings)
    // {
    //     for (PhysicThing *sThing : scene->staticThings)
    //     {
    //         bool collides = CheckCollisionRecs(dThing->collider, sThing->collider);
    //         if (collides)
    //         {
    //             float distance = 0;
    //             if (dThing->collider.y < sThing->collider.y)
    //             {
    //                 distance = (dThing->collider.y + (dThing->collider.height)) - sThing->collider.y;
    //             }
    //             else if (dThing->collider.y > sThing->collider.y)
    //             {
    //                 distance = dThing->collider.y - (sThing->collider.y + (sThing->collider.height));
    //             }
    //             distance = -distance;                   // Todavia no se por que, pero es necesario.
    //             dThing->thing->position.y += distance;
    //         }
    //     }
    // }
}

void AddThing(Scene *scene, Thing *thing)
{
    scene->thingsCounter++;
    thing->thingId = scene->thingsCounter;
    if (thing->hasPhysicalBody)
    {
        thing->physicalBody = (PhysicThing*)MemAlloc(sizeof(PhysicThing));
        thing->physicalBody->thing = thing;
        scene->physicalThings.push_back(thing->physicalBody);
    }
    scene->things.push_back(thing);
}

void DeleteThing(Scene *scene, int thingId)
{

}

Thing* FindThing(Scene *scene, int thingId)
{
    return scene->things[thingId];
}

// Scene LoadScene(const char *filename)
// {
//     Scene scene = {};
//     FILE *file = fopen(filename, "rb");
//     SceneFileHeader sceneHeader;
//     fread(&sceneHeader, sizeof(SceneFileHeader), 1, file);
//     scene.things.resize(sceneHeader.amountThings);
//     for (int i = 0; i < sceneHeader.amountAssets; i++)
//     {
//         SceneFileAsset sceneAsset;
//         fread(&sceneAsset, sizeof(SceneFileAsset), 1, file);
//         LoadAssetById(sceneAsset.assetId);
//     }
//     for (int i = 0; i < sceneHeader.amountThings; i++)
//     {
//         SceneFileThing sceneThing;
//         fread(&sceneThing, sizeof(SceneFileThing), 1, file);
//         Thing newThing = {};

//     }
//     fclose(file);
// }