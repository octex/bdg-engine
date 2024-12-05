#ifndef SCENES_H
#define SCENES_H

#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "things.h"
#include "assets.h"

#define RENDER_COLLIDERS true

// ----------------------------------------
//      Scene struct and main functions
// ----------------------------------------

typedef struct Scene
{
    std::vector<Thing*> things;
    std::vector<PhysicThing*> physicalThings;
} Scene;

void InitScene(Scene *scene);
void UpdateScene(Scene *scene);
void RenderScene(Scene *scene);
void UnloadScene(Scene *scene);

// -----------------------------------
//      Physics related functions
// -----------------------------------

void UpdateXAxis(Scene *scene);
void UpdateYAxis(Scene *scene);

// -------------------------------------------
//      Thing management related functions
// -------------------------------------------

void AddThing(Scene *scene, Thing *thing);
void DeleteThing(Scene *scene, int thingId);
Thing* FindThing(Scene *scene, int thingId);


// #define SCENE_FILE_FORMAT ".bdgscene"

//   =======================
//  |   SceneFile Header    |
//  |   SceneFile Assets    |
//  |   SceneFile Things    |
//   =======================
// typedef struct SceneFileHeader {
//     int sceneId, amountAssets, amountThings;
// } SceneFileHeader;

// typedef struct SceneFileAsset {
//     int assetId;
// } SceneFileAsset;

// typedef struct SceneFileThing {
//     unsigned int thingId;
//     ThingType thingType;
//     Vector2 position;
// } SceneFileThing;
// Scene LoadScene(const char *filename);
// void UnloadSceneToFile(Scene *scene);


#endif