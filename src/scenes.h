#ifndef SCENES_H
#define SCENES_H

#include <raylib.h>
#include <vector>
#include "things.h"


typedef struct Scene
{
    // std::vector <Asset*> assets; -> Missing files
    std::vector<Thing*> things;
} Scene;

//   _______________________
//  |   SceneFile Header    |
//  |   SceneFile Assets    |
//  |   SceneFile Things    |
//  |_______________________|

struct SceneFileHeader {
    int sceneId, amountAssets, amountThings;
} SceneFileHeader;

struct SceneFileAsset {
    // TODO: Migrate old files
} SceneFileAsset;

struct SceneFileThing {
    unsigned int thingId;
    ThingType thingType;
    Vector2 position;
} SceneFileAsset;

struct SceneFile {
   struct SceneFileHeader header;
} SceneFile;


void InitThings(Scene *scene);
void UpdateThings(Scene *scene);
void RenderThings(Scene *scene);

Scene* LoadScene(const char *filename);
void UnloadSceneToFile(Scene *scene);


#endif