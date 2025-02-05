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
    HandleCollisions(scene);
}

void RenderScene(Scene *scene)
{
    for (Thing *thing : scene->things)
    {
        RenderThing(thing);
    }
    if (DEVELOPER_MODE)
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
        // thing->collider.x = thing->thing->position.x - thing->collider.width / 2;
        thing->thing->position.x += thing->velocity.x;
        thing->collider.x = thing->thing->position.x;
    }

    for (PhysicThing *dThing : scene->dynamicThings)
    {
        for (PhysicThing *sThing : scene->staticThings)
        {
            bool collides = CheckCollisionRecs(dThing->collider, sThing->collider);
            if (collides)
            {
                CollisionPair newCollisionPair = {0};
                newCollisionPair.a = dThing->thing;
                newCollisionPair.b = sThing->thing;
                scene->collisionsToHandleX.push_back(newCollisionPair);
            }
        }
    }
}

void UpdateYAxis(Scene *scene)
{
    for (PhysicThing *thing : scene->dynamicThings)
    {
        // thing->collider.y = thing->thing->position.y - thing->collider.height / 2;
        // thing->thing->position.y += thing->velocity.y;
        thing->thing->position.y += thing->velocity.y;
        thing->collider.y = thing->thing->position.y;
    }

    for (PhysicThing *dThing : scene->dynamicThings)
    {
        for (PhysicThing *sThing : scene->staticThings)
        {
            bool collides = CheckCollisionRecs(dThing->collider, sThing->collider);
            if (collides)
            {
                CollisionPair newCollisionPair = {0};
                newCollisionPair.a = dThing->thing;
                newCollisionPair.b = sThing->thing;
                scene->collisionsToHandleY.push_back(newCollisionPair);
            }
        }
    }
}

void HandleCollisions(Scene *scene)
{
    for (CollisionPair collPair : scene->collisionsToHandleX)
    {
        if (!CheckCollisionRecs(collPair.a->physicalBody->collider, collPair.b->physicalBody->collider))
            continue;
        float distance = 0;
        
        PhysicThing *dThing = collPair.a->physicalBody;
        PhysicThing *sThing = collPair.b->physicalBody;
        
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
        dThing->collider.x = dThing->thing->position.x;
    }
    scene->collisionsToHandleX.clear();
    for (CollisionPair collPair : scene->collisionsToHandleY)
    {
        if (!CheckCollisionRecs(collPair.a->physicalBody->collider, collPair.b->physicalBody->collider))
            continue;
        float distance = 0;
        
        PhysicThing *dThing = collPair.a->physicalBody;
        PhysicThing *sThing = collPair.b->physicalBody;
        
        if (dThing->collider.y < sThing->collider.y)
        {
            distance = (dThing->collider.y + (dThing->collider.height)) - sThing->collider.y;
        }
        else if (dThing->collider.y > sThing->collider.y)
        {
            distance = dThing->collider.y - (sThing->collider.y + (sThing->collider.height));
        }
        distance = -distance;                   // Todavia no se por que, pero es necesario.
        dThing->thing->position.y += distance;
        dThing->collider.y = dThing->thing->position.y;
    }
    scene->collisionsToHandleY.clear();
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

void DebugThingData(SceneThingFile *sceneThingFile)
{
    std::cout << "Read Thing:" << std::endl;
    std::cout << "\tType:" << sceneThingFile->thingType << std::endl;
    std::cout << "\tPosition: " << sceneThingFile->x << " , " << sceneThingFile->y << std::endl;
    std::cout << "\tAmount of assets: " << sceneThingFile->amountOfAssets << std::endl;
}

Scene* LoadScene(int sceneId)
{
    Asset sceneAsset = assets[sceneId];

    if (!IsFileExtension(sceneAsset.dir, SCENE_FILEFORMAT))
    {
        return NULL;
    }
    
    Scene *scene = (Scene*)MemAlloc(sizeof(Scene));
    FILE *file = fopen(sceneAsset.dir, "rb");

    std::cout << "Loading scene: " << sceneAsset.dir << "..." << std::endl;

    SceneThingFile sceneThingFile;

    while(!feof(file))
    {
        sceneThingFile = {0};
        fread(&sceneThingFile.hasPhysicalBody, sizeof(bool), 1, file);
        fread(&sceneThingFile.ready, sizeof(bool), 1, file);
        fread(&sceneThingFile.x, sizeof(float), 1, file);
        fread(&sceneThingFile.y, sizeof(float), 1, file);
        fread(&sceneThingFile.amountOfAssets, sizeof(int), 1, file);
        fread(&sceneThingFile.thingType, sizeof(int), 1, file);
        fread(&sceneThingFile.assets, sizeof(int), sceneThingFile.amountOfAssets, file);
        if (sceneThingFile.ready)
        {
            DebugThingData(&sceneThingFile);
            Thing *newThing = (Thing*)MemAlloc(sizeof(Thing));
            newThing->thingType = (ThingType)sceneThingFile.thingType;
            newThing->position = (Vector2){sceneThingFile.x, sceneThingFile.y};
            for (int i = 0; i < sceneThingFile.amountOfAssets; i++)
            {
                std::cout << "\t\tAsset id: " << sceneThingFile.assets[i] << std::endl;
                newThing->assets.push_back(sceneThingFile.assets[i]);
            }
            newThing->hasPhysicalBody = sceneThingFile.hasPhysicalBody;
            AddThing(scene, newThing);
        }
    }
    std::cout << "Scene: " << sceneAsset.dir << " loaded" << std::endl;
    return scene;
}
