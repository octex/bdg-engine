#ifndef TBOX_ASSETS
#define TBOX_ASSETS

#include <map>
#include <stdlib.h>
#include "raylib.h"

#define ASSETS_DIR "resources/"

// typedef enum AssetType
// {
//     TEXTURE,
//     SOUND,
//     MODEL,
//     MUSIC,
//     SPRITE_SHEET,
//     SHADER,
// } AssetType;

typedef struct Asset
{
    int id;
    const char *dir;
    // AssetType assetType;
} Asset;

extern std::map<int, Asset> assets;
extern FilePathList assetsDirs;

// AssetType GetAssetTypeByFileExtension(const char* fileExtension);
// Asset* LoadAsset(const char* filename, AssetType assetType);
// Asset* LoadAsset(int assetId);

void LoadAssetsDirs();
void LoadAssets();

#endif