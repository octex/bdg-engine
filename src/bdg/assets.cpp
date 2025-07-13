#include "assets.h"
#include <iostream>

std::map<std::string, std::string> assetsIndex;
FilePathList assetsDirs;
std::map<std::string, Texture2D> textureMap;
std::map<std::string, std::string> scriptMap;

void LoadAssets()
{
    LoadAssetsDirs();
    for (int i = 0; i < assetsDirs.count; i++)
    {
        const char *path = assetsDirs.paths[i];
        const char *filename = GetFileName(path);
        assetsIndex.insert(std::pair<std::string, std::string>(filename, path));
    }
}

void LoadAssetsDirs()
{
    bool resExists = DirectoryExists(ASSETS_DIR);
    if (!resExists)
    {
        exit(-1);
    }
    assetsDirs = LoadDirectoryFilesEx(ASSETS_DIR, NULL, true);
}

void UnloadAssetsDirs()
{
    UnloadDirectoryFiles(assetsDirs);
}

void GetAsset(std::string alias, AssetType assetType, void* asset)
{
    switch (assetType)
    {
        case ASSET_TEXTURE:
        {
            if (textureMap.count(alias) == 0)
            {
                textureMap[alias] = LoadTexture(assetsIndex[alias].c_str());
            }
            (*(Texture2D*)asset) = textureMap[alias];
        }
            break;
        case ASSET_SCENE:
        {
            (*(std::string*)asset) = assetsIndex[alias];
        }
            break;
        case ASSET_SCRIPT:
        {
            (*(std::string*)asset) = assetsIndex[alias];
        }
            break;
        default:
            break;
    }
}

void LoadAsset(std::string alias, AssetType assetType)
{
    switch (assetType)
    {
        case ASSET_TEXTURE:
        {
            if (textureMap.count(alias) == 0)
            {
                textureMap[alias] = LoadTexture(assetsIndex[alias].c_str());
            }
        }
            break;
        case ASSET_SCENE:
            break;
        case ASSET_SCRIPT:
            break;
        default:
            break;
    }
}