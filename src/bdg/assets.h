#ifndef TBOX_ASSETS
#define TBOX_ASSETS

#include <map>
#include <string>
#include <stdlib.h>
#include "raylib.h"

#define ASSETS_DIR "resources/"

extern std::map<std::string, const char *> assets;
extern FilePathList assetsDirs;

typedef enum AssetType
{
    ASSET_TEXTURE,
    ASSET_SCENE,
    ASSET_SCRIPT
} AssetType;

void LoadAssetsDirs();
void LoadAssets();
void UnloadAssetsDirs();

#endif