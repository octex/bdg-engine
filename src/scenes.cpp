#include "scenes.h"

void InitScene(Scene *scene)
{
    for (Thing thing : scene->things)
    {
        InitThing(thing);
    }
}

void UpdateScene(Scene *scene)
{
    for (Thing thing : scene->things)
    {
        UpdateThing(thing);
    }
}

void RenderScene(Scene *scene)
{
    for (Thing thing : scene->things)
    {
        RenderThing(thing);
    }
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