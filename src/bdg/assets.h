#ifndef TBOX_ASSETS
#define TBOX_ASSETS

#include <map>
#include <string>
#include <stdlib.h>
#include "raylib.h"

#define ASSETS_DIR "resources/"

extern std::map<std::string, std::string> assetsIndex;
extern FilePathList assetsDirs;

typedef enum AssetType
{
    ASSET_TEXTURE,
    ASSET_SCENE,
    ASSET_SCRIPT
} AssetType;

typedef struct Asset
{
    const char* path;
    AssetType assetType;
} Asset;

// Mappers
extern std::map<std::string, Texture2D> textureMap;
extern std::map<std::string, std::string> scriptMap;

void LoadAssetsDirs();
void LoadAssets();
void UnloadAssetsDirs();

// template <typename T>
void GetAsset(std::string alias, AssetType assetType, void* asset);

#endif