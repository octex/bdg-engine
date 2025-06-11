#include "scenes.h"

#include <iostream>

Scene* CreateScene()
{
    Scene *newScene = (Scene*)MemAlloc(sizeof(Scene));
    newScene->thingsCounter = 0;
    newScene->things = {};
    newScene->physicalThings = {};
    newScene->staticThings = {};
    newScene->dynamicThings = {};
    newScene->collisionsToHandleX = {};
    newScene->collisionsToHandleY = {};
    return newScene;
}

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


Scene* LoadScene(std::string filename)
{
    Scene *newScene = CreateScene();
    sol::state lua = ReadLuaFile(filename);

    sol::table things = lua["things"];

    for (int i = 1; i <= things.size(); i++)
    {
        sol::table thing = things[i];

        Vector2 thingPosition = (Vector2){thing["x"], thing["y"]};
        ThingType thingType = (ThingType)thing["thing_type"];
        sol::table thingAttrs = thing["attributes"];
        Thing *newThing = CreateThing(thingPosition, thingType, thing["has_physical_body"]);
        for (int i = 1; i <= (int)thing["attributes_len"]; i++)
        {
            sol::table attr = thingAttrs[i];
            if ((std::string)attr["datatype"] == "i")
            {
                SetThingAttr(newThing, static_cast<std::string>(attr["attr"]), (int)attr["value"]);
            }
            else if ((std::string)attr["datatype"] == "f")
            {
                SetThingAttr(newThing, static_cast<std::string>(attr["attr"]), (float)attr["value"]);
            }
            else if ((std::string)attr["datatype"] == "s")
            {
                SetThingAttr(newThing, static_cast<std::string>(attr["attr"]), (std::string)attr["value"]);
            }
        }
        AddThing(newScene, newThing);
    }

    return newScene;
}