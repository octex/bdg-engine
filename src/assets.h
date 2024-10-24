#ifndef TBOX_ASSETS
#define TBOX_ASSETS

#define BASE_ASSETS_SIZE_ARR 1

#include <stdlib.h>
#include "raylib.h"

typedef enum AssetType
{
    TEXTURE,
    SOUND,
    MODEL,
    MUSIC,
    SPRITE_SHEET,
    SHADER,
} AssetType;

typedef struct Asset
{
    int id;
    void *asset;        // Use: *(Texture*)asset syntax
} Asset;

extern Asset* assets[BASE_ASSETS_SIZE_ARR];
extern int amountOfAssets;

Asset* LoadAsset(const char* filename, AssetType assetType);
AssetType GetAssetTypeByFileExtension(const char* fileExtensionn);
// Asset* LoadAsset(int assetId);
Asset GetAsset(int assetId);

void LoadBaseAssets();
void UnloadBaseAssets();

#endif