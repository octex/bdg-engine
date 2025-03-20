#include "assets.h"

std::map<int, Asset> assets;
FilePathList assetsDirs;


void LoadAssets()
{
    LoadAssetsDirs();
    for (int i = 0; i < assetsDirs.count; i++)
    {
        const char *path = assetsDirs.paths[i];
        const char *filename = GetFileName(path);
        const char *fileNameWithoutExt = GetFileNameWithoutExt(path);
        const char *fileExtension = GetFileExtension(filename);
        int assetId = atoi(fileNameWithoutExt);
        Asset newAsset = {};
        newAsset.id = assetId;
        newAsset.dir = path;
        assets.insert(std::pair<int, Asset>(assetId, newAsset));
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
