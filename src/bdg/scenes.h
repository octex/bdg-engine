#ifndef SCENES_H
#define SCENES_H

#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <string>
#include "bdg_lua.h"
#include "things.h"
#include "assets.h"
#include "settings.h"

// ----------------------------------------
//      Scene struct and main functions
// ----------------------------------------

typedef struct Scene
{
    int thingsCounter;
    std::vector<Thing*> things;
    std::vector<PhysicThing*> physicalThings;
    std::vector<PhysicThing*> staticThings;
    std::vector<PhysicThing*> dynamicThings;
    std::vector<CollisionPair> collisionsToHandleX;
    std::vector<CollisionPair> collisionsToHandleY;
} Scene;

void InitScene(Scene *scene);
void UpdateScene(Scene *scene);
void RenderScene(Scene *scene);
void UnloadScene(Scene *scene);

Scene* CreateScene();

// -----------------------------------
//      Physics related functions
// -----------------------------------

void UpdateXAxis(Scene *scene);
void UpdateYAxis(Scene *scene);
void HandleCollisions(Scene *scene);

// -------------------------------------------
//      Thing management related functions
// -------------------------------------------

void AddThing(Scene *scene, Thing *thing);
void DeleteThing(Scene *scene, int thingId);
Thing* FindThing(Scene *scene, int thingId);


// ---------------------------------------
//      Scene file management functions
// ---------------------------------------

Scene* LoadScene(std::string filePath);

#endif