#include "scenes.h"

void InitScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        InitThing(thing);
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
    for (PhysicThing *thing : scene->physicalThings)
    {
        thing->thing->position.x += thing->velocity.x;
    }
}

void UpdateYAxis(Scene *scene)
{
    for (PhysicThing *thing : scene->physicalThings)
    {
        thing->thing->position.y += thing->velocity.y;
    }
}

void AddThing(Scene *scene, Thing *thing)
{
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
    return NULL;
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