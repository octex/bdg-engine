#ifndef SCENES_H
#define SCENES_H

#include <raylib.h>
#include <vector>
#include "things.h"
#include "assets.h"

// #define SCENE_FILE_FORMAT ".bdgscene"


typedef struct Scene
{
    std::vector<Thing> things;
} Scene;

void InitScene(Scene *scene);
void UpdateScene(Scene *scene);
void RenderScene(Scene *scene);


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